#include <iostream>
#include <string>

using namespace std;

bool isMatchImp(string sStr, string sMatch, int nIndexStr, int nIndexMatch)
{
    // �ַ�����������ʽ������β�ˣ��Ǿ���ƥ��ɹ�
    if(nIndexStr >= sStr.size() && nIndexMatch >= sMatch.size())
    {
        return true;
    }

    // �ַ�����û�꣬��������ʽ�Ѿ�����β�ˣ��Ǿ���ƥ��ʧ��
    // ���磬isMatch("aa", "a")
    if(nIndexStr < sStr.size() && nIndexMatch >= sMatch.size())
    {
        return false;
    }

    if(nIndexMatch+1 < sMatch.size() && '*' == sMatch[nIndexMatch+1]) // ���� * �����
    {
        // nIndexMatch+1 ��*�����ȡǰһ���ַ���nIndexMatchλ���ϵģ�
        // ҲҪ����������ʽ��*ǰ����.���������ʱ���str�Ѿ�����β�ˣ�Ҳ��ƥ��ģ����str����β�ˣ�����������±�����
        if(sMatch[nIndexMatch] == sStr[nIndexStr]
           || ('.' == sMatch[nIndexMatch] && nIndexStr < sStr.size()))
        {
            return isMatchImp(sStr, sMatch, nIndexStr+1, nIndexMatch+2) // ���һ��*��ʾstrǰ��ֻ��һ���ַ�
                || isMatchImp(sStr, sMatch, nIndexStr+1, nIndexMatch)   // �������*��ʾstrǰ���в�ֹһ���ַ�
                || isMatchImp(sStr, sMatch, nIndexStr, nIndexMatch+2);  // �������*��ʾstrǰ��ֻ��0���ַ�
        }
        else
        {
            // ����*����ƥ��0������˴��ڲ�ƥ����������ֱ��������ƥ���
            // ���紦��������� isMatch("aab", "c*a*b)
            return isMatchImp(sStr, sMatch, nIndexStr, nIndexMatch+2);
        }
    }

    // ����һһƥ������
    // ���� . �������.������һ���ַ���
    if((nIndexStr < sStr.size() && nIndexMatch < sMatch.size() && sStr[nIndexStr] == sMatch[nIndexMatch])
       || (nIndexMatch < sMatch.size() && '.' == sMatch[nIndexMatch] && nIndexStr < sStr.size()))
    {
        return isMatchImp(sStr, sMatch, nIndexStr+1, nIndexMatch+1);
    }

    return false;
}

bool isMatch(string s, string p)
{
    // isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") �ᳬʱ�������һЩԤ�����
    string sPrefix;
    if(p.length() > 2)
    {
        sPrefix.push_back(p[0]);
        sPrefix.push_back(p[1]);

        int nIndexPrefix = 1;

        for(int i=2; i<p.length(); ++i)
        {
            if(p[i] == sPrefix[nIndexPrefix-1] && p[i+1] == sPrefix[nIndexPrefix])
            {
                ++i;
                continue;
            }
            else
            {
                ++nIndexPrefix;
                sPrefix.push_back(p[i]);
            }
        }
    }
    else
    {
        sPrefix = p;
    }
    //cout << "sPrefix:" << sPrefix << endl;

    return isMatchImp(s, sPrefix, 0, 0);
}

int main(int argc, char** argv)
{
    cout << isMatch("aa", "a") << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << isMatch("ab", ".*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
    cout << isMatch("mississippi", "mis*is*p*.") << endl;
    cout << isMatch("", ".*") << endl;      // 1
    cout << isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") << endl;
    cout << isMatch("bbbacbcbcbbbbabbbab", "b*c*c*.*.*.*ab*c") << endl;

    return 0;
}
