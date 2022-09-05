#include <iostream>
#include <string>

using namespace std;

bool isNumber(string s)
{
    bool bNumber = false;
    bool bOtherChar = false;
    for(int i=0; i<s.length(); ++i)
    {
        if((s[i] != 'e' && s[i] != 'E'
           && s[i] != '+' &&  s[i] != '-'
           && s[i] != ' ' &&  s[i] != '.')
           && s[i] != '0' &&  s[i] != '1'
           && s[i] != '2' &&  s[i] != '3'
           && s[i] != '4' &&  s[i] != '5'
           && s[i] != '6' &&  s[i] != '7'
           && s[i] != '8' &&  s[i] != '9')
        {
            return false;
        }

        if(i < s.length() && (s[i] == '+' || s[i] == '-'))
        {
            bOtherChar = true;
            // +-前面不能是数字
            if(i-1 >= 0 && ((s[i-1] >= '0' && s[i-1] <= '9') || (s[i-1] == '+' || s[i-1] == '-')))
                return false;
            ++i;
            if(i < s.length() && (s[i] == '+' || s[i] == '-'))
            {
                return false;
            }
        }

        bool hasNumber = false;
        while(i < s.length() && s[i] >= '0' && s[i] <= '9')     // 把数组遍历掉
        {
            bNumber = true;
            hasNumber = true;
            ++i;
        }
        if(hasNumber && i < s.length() && (s[i] == '+' || s[i] == '-'))
            return false;

        if(i < s.length() && s[i] == '.')
        {
            bOtherChar = true;
            ++i;
            if(i < s.length() && s[i] == '.')
            {
                return false;
            }

            if(i < s.length() && (s[i] == '+' || s[i] == '-'))
            {
                return false;
                if(i-1 >= 0 && ((s[i-1] >= '0' && s[i-1] <= '9') || (s[i-1] == '+' || s[i-1] == '-')))
                    return false;
                ++i;
                if(i < s.length() && ((s[i] == '+' || s[i] == '-') || (s[i] >= '0' && s[i] <= '9')))
                {
                    return false;
                }
            }
            bool bHasNumAferPoint = false;
            while(i < s.length() && s[i] >= '0' && s[i] <= '9')     // 把数组遍历掉
            {
                bHasNumAferPoint = true;
                ++i;
            }
            if(bHasNumAferPoint && i < s.length() && (s[i] == '+' || s[i] == '-'))
                return false;

            // 该数字前面是个.，那后面不能再有点
            if(bHasNumAferPoint)
            {
                if(i < s.length() && s[i] == '.')
                {
                    return false;
                }
            }

            // 小数点前面没有数字，后面也没有数字
            if(false == bNumber && false == bHasNumAferPoint)
            {
                return false;
            }
            if(true == bHasNumAferPoint)
            {
                bNumber = bHasNumAferPoint;
            }
        }

        if(i < s.length() && (s[i] == 'e' || s[i] == 'E'))
        {
            bOtherChar = true;
            // 遍历到这里，如果bNumber是false，则证明e前面没有数字
            if(false == bNumber)
            {
                return false;
            }

            ++i;

            if(i < s.length() && (s[i] == '+' || s[i] == '-'))
            {
                if(i-1 >= 0 && ((s[i-1] >= '0' && s[i-1] <= '9') || (s[i-1] == '+' || s[i-1] == '-')))
                    return false;
                ++i;
                if(i < s.length() && (s[i] == '+' || s[i] == '-'))
                {
                    return false;
                }
            }
            bool bHasNumAferE = false;
            while(i < s.length() && s[i] >= '0' && s[i] <= '9')     // 把数组遍历掉
            {
                bHasNumAferE = true;
                ++i;
            }
            if(bHasNumAferE && i < s.length() && (s[i] == '+' || s[i] == '-'))
                return false;

            // E后面是整数
            if(i < s.length() && s[i] == '.')
            {
                return false;
            }

            if((i < s.length() && (s[i] == 'e' || s[i] == 'E')) ||
               ((i+1) < s.length() && (s[i] == 'e' || s[i] == 'E') && (s[i+1] == ' ' || s[i+1] == '.')))
            {
                return false;
            }

            // E后面没有数字
            if(false == bHasNumAferE)
            {
                return false;
            }
            bNumber = bHasNumAferE;
        }

        // 考虑间隔了空格的情况
        if((true == bNumber || true == bOtherChar)
            && (i < s.length() && s[i] == ' ')
            && (i+1 < s.length() && s[i+1] != ' '))
        {
            return false;
        }

        if(i < s.length() && (s[i] != 'e' && s[i] != 'E'
           && s[i] != '+' &&  s[i] != '-'
           && s[i] != ' ' &&  s[i] != '.'
           && s[i] != '0' &&  s[i] != '1'
           && s[i] != '2' &&  s[i] != '3'
           && s[i] != '4' &&  s[i] != '5'
           && s[i] != '6' &&  s[i] != '7'
           && s[i] != '8' &&  s[i] != '9'))
        {
            return false;
        }
    }

    return bNumber;
}

int main(int argc, char** argv)
{
    cout << isNumber("0") << endl;
    cout << isNumber("e") << endl;
    cout << isNumber(".") << endl;
    cout << isNumber("    .1  ") << endl;
    cout << isNumber("e9") << endl;     // false
    cout << isNumber("0e") << endl;     // false
    cout << isNumber("..2") << endl;    // false
    cout << isNumber("3.") << endl;     // true
    cout << isNumber("1 4") << endl;    // false
    cout << isNumber("0..") << endl;    // false
    cout << isNumber(".0e") << endl;    // false
    cout << isNumber("-1E-16") << endl; // true
    cout << isNumber(".1.") << endl;    // false
    cout << isNumber("G76") << endl;    // false
    cout << isNumber("53K") << endl;    // false

    cout << "------------------" << endl;    // false
    cout << isNumber("12e") << endl;    // false
    cout << isNumber("1a3.14") << endl;    // false
    cout << isNumber("1.2.3") << endl;    // false
    cout << isNumber("+-5") << endl;    // false
    cout << isNumber("12e+5.4") << endl;    // false
    cout << isNumber("6+1") << endl;    // false
    cout << isNumber(".8+") << endl;    // false
    cout << isNumber(".-4") << endl;    // false
    cout << isNumber("+ 1") << endl;    // false
    cout << isNumber("5.-") << endl;    // false
    cout << isNumber("7e69e") << endl;    // false
    cout << isNumber("2e8e ") << endl;    // false
    cout << isNumber("2e8e  ") << endl;    // false

    return 0;

}
