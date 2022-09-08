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
            // 第 i 个字符和第 nIndex 个字符作交换
            char cTmp = s[nIndex];
            s[nIndex] = s[i];
            s[i] = cTmp;

            // 交换之后，再看剩余部分，因此 nIndex+1
            permutationImp(s, nIndex+1, vecRet);

            // 再换回来，然后进入下一轮循环时，与后面的字符再交换
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

    // 做一下去重
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
