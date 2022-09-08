#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void permutationImp(string& s, int nIndex, vector<string>& vecRet)
{
    if(nIndex == s.length())
    {
        vecRet.push_back(s);
    }
    else
    {
        for(int i=nIndex; i<s.length(); ++i)
        {
            // �� i ���ַ��͵� nIndex ���ַ�������
            char cTmp = s[nIndex];
            s[nIndex] = s[i];
            s[i] = cTmp;

            // ����֮���ٿ�ʣ�ಿ�֣���� nIndex+1
            permutationImp(s, nIndex+1, vecRet);

            // �ٻ�������Ȼ�������һ��ѭ��ʱ���������ַ��ٽ���
            cTmp = s[nIndex];
            s[nIndex] = s[i];
            s[i] = cTmp;
        }
    }
}

vector<string> permutation(string s)
{
    vector<string> vecRet;
    permutationImp(s, 0, vecRet);

    // ��һ��ȥ��
    set<string> setRet;
    for(const auto item : vecRet)
        setRet.insert(item);
    vector<string> vecRetFinal;
    for(const auto item : setRet)
        vecRetFinal.push_back(item);
    return vecRetFinal;
}

int main(int argc, char** argv)
{
    vector<string> vecRet = permutation("aab");
    for(const auto item : vecRet)
        cout << "item : " << item << endl;

    return 0;
}
