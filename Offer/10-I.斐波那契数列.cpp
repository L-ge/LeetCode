#include <iostream>
#include <stack>

using namespace std;

int fib2(int n)
{
    if(0 == n)
        return 0;
    if(1 == n)
        return 1;

    return fib2(n-1) + fib2(n-2);
}

int fib(int n)
{
    // ���õݹ飬�ᳬʱ��
    // ȥ���ݹ��д����ظ��ļ��㣬������ f(0) �� f(1) ��� f(2)������ f(1) �� f(2) ��� f(3)��...
    if(0 == n)
        return 0;
    if(1 == n)
        return 1;

    long long nFirstPart = 0;
    long long nSecondPart = 1;
    long long nResult = 0;
    for(int i=2; i<=n; ++i)
    {
        nResult = (nFirstPart + nSecondPart) % 1000000007;
        nFirstPart = nSecondPart;
        nSecondPart = nResult;
    }

    return nResult % 1000000007;
}

int main(int argc, char** argv)
{
    cout << fib(0) << endl;
    cout << fib(1) << endl;
    cout << fib(2) << endl;
    cout << fib(5) << endl;
    cout << fib(95) << endl;

    /*for(int i=0; i<=100; ++i)
    {
        int nFib1 = fib(i);
        int nFib2 = fib2(i) % 1000000007;
        if(nFib1 != nFib2)
        {
            cout << "error:" << i << ", fib=" << nFib1 << ", fib2=" << nFib2;
        }
    }*/
    cout << "fin";
    return 0;
}
