#include <iostream>

using namespace std;

double myPowImp(double x, long long n)
{
    // ���÷ֽ�ݹ�ķ���
    // x^n = x^(n/2) * x^(n/2)          , nΪż��
    // x^n = x^(n/2) * x^(n/2) * n      ��nΪ����
    if(0 == n)
        return 1;
    if(1 == n)
        return x;

    double lfResult = myPowImp(x, n / 2);
    lfResult = lfResult * lfResult;
    if(1 == n % 2)  // ����
        lfResult *= x;

    return lfResult;
}

double myPow(double x, int n)
{
    long long nActualPow = n;
    if(n < 0)
    {
        nActualPow = (long long)-nActualPow;    // Ҫ��-nActualPow��������-n
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
