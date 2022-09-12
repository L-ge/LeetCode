#include <iostream>
#include <string>
#include <map>

using namespace std;

// ���ַ��� s ���ҳ���һ��ֻ����һ�ε��ַ������û�У�����һ�����ո� s ֻ����Сд��ĸ��
// 0 <= s �ĳ��� <= 50000
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
