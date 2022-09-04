#include <iostream>
#include <string>

using namespace std;

bool isMatchImp(string sStr, string sMatch, int nIndexStr, int nIndexMatch)
{
    // 字符串和正则表达式都到结尾了，那就是匹配成功
    if(nIndexStr >= sStr.size() && nIndexMatch >= sMatch.size())
    {
        return true;
    }

    // 字符串还没完，但正则表达式已经到结尾了，那就是匹配失败
    // 例如，isMatch("aa", "a")
    if(nIndexStr < sStr.size() && nIndexMatch >= sMatch.size())
    {
        return false;
    }

    if(nIndexMatch+1 < sMatch.size() && '*' == sMatch[nIndexMatch+1]) // 处理 * 的情况
    {
        // nIndexMatch+1 是*，则读取前一个字符（nIndexMatch位置上的）
        // 也要考虑正则表达式的*前面是.的情况，此时如果str已经到结尾了，也是匹配的；如果str到结尾了，无需继续往下遍历了
        if(sMatch[nIndexMatch] == sStr[nIndexStr]
           || ('.' == sMatch[nIndexMatch] && nIndexStr < sStr.size()))
        {
            return isMatchImp(sStr, sMatch, nIndexStr+1, nIndexMatch+2) // 情况一：*表示str前面只有一个字符
                || isMatchImp(sStr, sMatch, nIndexStr+1, nIndexMatch)   // 情况二：*表示str前面有不止一个字符
                || isMatchImp(sStr, sMatch, nIndexStr, nIndexMatch+2);  // 情况三：*表示str前面只有0个字符
        }
        else
        {
            // 考虑*允许匹配0个，因此存在不匹配的情况，那直接跳过该匹配符
            // 例如处理这种情况 isMatch("aab", "c*a*b)
            return isMatchImp(sStr, sMatch, nIndexStr, nIndexMatch+2);
        }
    }

    // 处理一一匹配的情况
    // 处理 . 的情况，.是任意一个字符。
    if((nIndexStr < sStr.size() && nIndexMatch < sMatch.size() && sStr[nIndexStr] == sMatch[nIndexMatch])
       || (nIndexMatch < sMatch.size() && '.' == sMatch[nIndexMatch] && nIndexStr < sStr.size()))
    {
        return isMatchImp(sStr, sMatch, nIndexStr+1, nIndexMatch+1);
    }

    return false;
}

bool isMatch(string s, string p)
{
    // isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") 会超时，因此做一些预处理吧
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
