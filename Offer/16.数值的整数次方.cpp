#include <iostream>

using namespace std;

double myPowImp(double x, long long n)
{
    // 利用分解递归的方法
    // x^n = x^(n/2) * x^(n/2)          , n为偶数
    // x^n = x^(n/2) * x^(n/2) * n      ，n为奇数
    if(0 == n)
        return 1;
    if(1 == n)
        return x;

    double lfResult = myPowImp(x, n / 2);
    lfResult = lfResult * lfResult;
    if(1 == n % 2)  // 奇数
        lfResult *= x;

    return lfResult;
}

double myPow(double x, int n)
{
    long long nActualPow = n;
    if(n < 0)
    {
        nActualPow = (long long)-nActualPow;    // 要用-nActualPow，不能用-n
    }

    double lfResult = myPowImp(x, nActualPow);
    if(n < 0)
    {
        return 1/lfResult;
    }
    return lfResult;
}

int main(int argc, char** argv)
{
    cout << myPow(2.00000, 10) << endl;
    cout << myPow(2.10000, 3) << endl;
    cout << myPow(2.00000, -2) << endl;
    cout << myPow(1.00000, -2147483648) << endl;

    return 0;
}
