#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string reverseLeftWords(string s, int n)
{
    queue<char> queueCache;
    for(int i=0; i<n; ++i)
    {
        queueCache.push(s[i]);
    }
    string sRet;
    for(int i=n; i<s.length(); ++i)
    {
        sRet.append(1, s[i]);
    }
    while(false == queueCache.empty())
    {
        char cTmp = queueCache.front();
        queueCache.pop();
        sRet.append(1, cTmp);
    }
    return sRet;
}

int main(int argc, char** argv)
{
    cout << reverseLeftWords("abcdefg", 2) << endl;     // cdefgab
    cout << reverseLeftWords("lrloseumgh", 6) << endl;     // umghlrlose

    return 0;
}
