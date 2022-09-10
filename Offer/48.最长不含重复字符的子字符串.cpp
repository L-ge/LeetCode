#include <iostream>
#include <map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    // ����һ��map�������洢ÿ���ַ��ϴγ������ַ�����λ�õ��±�
    map<char, int> mapPosition;

    // ����㷨���൱�ڼ���ĳ���ַ��ϴγ��ֵĳ��ȣ�Ȼ���һֱ���±�����
    // �������û�з��ʹ���Ԫ�ػ��ߺܾ�֮ǰ���ʵ�Ԫ�أ��Ӵ����Ⱦ�+1��
    // ��������˷��ʹ���Ԫ����û��òŷ������Ԫ�أ���Ҫ���̵�ǰ�Ӵ��ĳ��ȣ�
    // ����Ϊ ��һ�η��ʵ�Ԫ�غ͵�ǰ�ٴη��ʵ���Ԫ�صļ����
    int nCurLength = 0;
    int nMaxLength = 0;
    for(int i=0; i<s.length(); ++i)
    {
        int nPreIndex = -1;
        if(mapPosition.count(s[i]) > 0)
            nPreIndex = mapPosition[s[i]];  // ��ǰ�ַ��ϴε��±�

        // 1��nPreIndex < 0 ����˼�Ǹ��ַ�û�г��ֹ�
        // 2��i-nPreIndex > nCurLength ����˼�Ǹ��ַ��ϴγ��ֵ�λ�ú͵�ǰλ�õĲҲ���ǳ��ȣ������˵�ǰ�Ӵ��ĳ���
        // ��ô����Ϊ���ַ���Ч��û�д����ظ��ַ�������˵�ǰ�Ӵ�����+1
        if(nPreIndex < 0 || i-nPreIndex > nCurLength)
        {
            ++nCurLength;
        }
        else
        {
            if(nCurLength > nMaxLength)     // ������Ӵ�����
                nMaxLength = nCurLength;
            nCurLength = i - nPreIndex;
        }
        mapPosition[s[i]] = i;      // ��¼��ǰ�ַ����±�
    }

    if(nCurLength > nMaxLength)     // ������Ӵ�����
        nMaxLength = nCurLength;

    return nMaxLength;
}

int main(int argc, char** argv)
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    cout << lengthOfLongestSubstring(" ") << endl;

    return 0;
}
