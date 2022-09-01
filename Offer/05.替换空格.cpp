#include <iostream>
#include <string>

using namespace std;

string replaceSpace(string s)
{
    int nStrLength = s.length();
    if(0 == nStrLength)
        return "";

    // 算出空白字符的个数
    int nCntBlank = 0;
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == ' ')
            ++nCntBlank;
        ++i;
    }

    int nNewLength = nStrLength + nCntBlank*2;
    s.resize(nNewLength);

    int nIndexOfOrigin = nStrLength - 1;
    int nIndexOfNew = nNewLength - 1;
    while(nStrLength >= 0 && nIndexOfNew > nIndexOfOrigin)
    {
        if(s[nIndexOfOrigin] == ' ')      // 在字符末端加上替换的字符串
        {
            s[nIndexOfNew] = '0';
            --nIndexOfNew;
            s[nIndexOfNew] = '2';
            --nIndexOfNew;
            s[nIndexOfNew] = '%';
            --nIndexOfNew;
        }
        else
        {
            s[nIndexOfNew] = s[nIndexOfOrigin];
            --nIndexOfNew;
        }

        --nIndexOfOrigin;
    }
    return s;
}

int main(int argc, char** argv)
{
    cout << replaceSpace("We are happy.");
    return 0;
}
