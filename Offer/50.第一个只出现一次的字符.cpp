#include <iostream>
#include <string>
#include <map>

using namespace std;

// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
// 0 <= s 的长度 <= 50000
char firstUniqChar(string s)
{
    map<char, int> mapCache;
    for(int i=0; i<s.length(); ++i)
    {
        if(mapCache.count(s[i]) > 0)
            ++mapCache[s[i]];
        else
            mapCache[s[i]] = 1;
    }
    for(int i=0; i<s.length(); ++i)
    {
        if(1 == mapCache[s[i]])
            return s[i];
    }
    return ' ';
}

int main(int argc, char** argv)
{
    cout << firstUniqChar("abaccdeff") << endl;
    cout << firstUniqChar("") << endl;

    return 0;
}
