#include <iostream>
#include <map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    // 定义一个map，用来存储每个字符上次出现在字符串中位置的下标
    map<char, int> mapPosition;

    // 这个算法就相当于记着某个字符上次出现的长度，然后就一直往下遍历，
    // 如果遇到没有访问过的元素或者很久之前访问的元素，子串长度就+1，
    // 如果遇到了访问过的元素且没多久才访问完的元素，就要缩短当前子串的长度，
    // 缩短为 上一次访问的元素和当前再次访问到的元素的间隔。
    int nCurLength = 0;
    int nMaxLength = 0;
    for(int i=0; i<s.length(); ++i)
    {
        int nPreIndex = -1;
        if(mapPosition.count(s[i]) > 0)
            nPreIndex = mapPosition[s[i]];  // 当前字符上次的下标

        // 1、nPreIndex < 0 的意思是该字符没有出现过
        // 2、i-nPreIndex > nCurLength 的意思是该字符上次出现的位置和当前位置的差（也就是长度）超过了当前子串的长度
        // 那么就认为该字符有效（没有存在重复字符），因此当前子串长度+1
        if(nPreIndex < 0 || i-nPreIndex > nCurLength)
        {
            ++nCurLength;
        }
        else
        {
            if(nCurLength > nMaxLength)     // 更新最长子串长度
                nMaxLength = nCurLength;
            nCurLength = i - nPreIndex;
        }
        mapPosition[s[i]] = i;      // 记录当前字符的下标
    }

    if(nCurLength > nMaxLength)     // 更新最长子串长度
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
