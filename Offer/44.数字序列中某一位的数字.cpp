#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findNthDigit(int n)
{
    // 0 1 2 3 4 ...拼接起来的字符串
    // string s = "01234567891011121314151617181920";
    int nCurDigit = 1;      // 当前位数，比如个位就是1，十位是2，百位是3...
    while(true)             // 不知道输入会多大，所以无休止，里面再return
    {
        long long nCurDigitNumberCnt = 0;
        if(1 == nCurDigit)
            nCurDigitNumberCnt = 10;    // 个位有10个数字
        else                // 比如2位的数字，有9*10个；3位的数字有9*100个。
            nCurDigitNumberCnt = 9*pow(10, nCurDigit-1);

        long long nCostChar = nCurDigitNumberCnt * nCurDigit;
        if(n < nCostChar)   // 在nCostChar前面，因此要在前面找到该位置
        {
            long long nCurDigitBeginIndex = -1;
            if(1 == nCurDigit)
                nCurDigitBeginIndex = 0;
            else
                nCurDigitBeginIndex = pow(10, nCurDigit-1);

            // 每个数字占了nCurDigit位，比如17，这里算出来应该是10+(17-10)/2=13
            nCurDigitBeginIndex += (n / nCurDigit);
            long long nPosition = nCurDigit - n % nCurDigit;  // 算出偏移量，比如17，这里算出来应该是2-(17-10)%2=1
            for(int i=1; i<nPosition; ++i)
                nCurDigitBeginIndex /= 10;      // 这里就算出3了
            return nCurDigitBeginIndex % 10;
        }

        n -= nCostChar;   // 比如个位占了10个字符，百位占了90*2个字符
        ++nCurDigit;
    }
    return -1;
}

int main(int argc, char** argv)
{
    cout << findNthDigit(3) << endl;      // 3
    cout << findNthDigit(11) << endl;     // 0
    cout << findNthDigit(17) << endl;     // 3
    return 0;
}
