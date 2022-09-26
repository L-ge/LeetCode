#include <iostream>
#include <string>

using namespace std;

int strToInt(string str)
{
    int nIndex = 0;
    bool bNegative = false;

    // ȥ��ǰ��Ŀո�
    while(nIndex < str.size() && str[nIndex] == ' ')
        ++nIndex;

    // �ж�������
    if(str[nIndex] == '-')
    {
        bNegative = true;
        ++nIndex;
    }
    else if(str[nIndex] == '+')
    {
        bNegative = false;
        ++nIndex;
    }
    else if(str[nIndex] < '0' && str[nIndex] > '9')
    {
        return 0;
    }

    // ȥ��ǰ��0
    while(nIndex < str.size() && str[nIndex] == '0')
        ++nIndex;

    long long nRet = 0;
    while(nIndex < str.size() && str[nIndex] >= '0' && str[nIndex] <= '9')
    {
        nRet = nRet * 10 + (str[nIndex] - '0');

        if(nRet >= INT_MAX && false == bNegative)
            return INT_MAX;
        if(nRet > INT_MAX && true == bNegative)
            return INT_MIN;

        ++nIndex;
    }
    return bNegative ? -nRet : nRet;
}

int main(int argc, char** argv)
{
    cout << strToInt("42") << endl;
    cout << strToInt("   -42") << endl;
    cout << strToInt("4193 with words") << endl;
    cout << strToInt("words and 987") << endl;
    cout << strToInt("-91283472332") << endl;
    return 0;
}
