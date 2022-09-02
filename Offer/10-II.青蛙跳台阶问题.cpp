#include <iostream>
#include <stack>

using namespace std;

int numWays(int n)
{
    // 也就是斐波那契数列
    // 例如，第一次跳一级，那么剩余跳数为 n-1 级台阶的跳数；第一次跳二级，那么剩余跳数为 n-2 级台阶的跳数...
    // 也即 f(n) = f(n-1) + f(n-2)
    if(0 == n)
        return 1;
    if(1 == n)
        return 1;

    long long nFirstPart = 1;
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
    cout << numWays(0) << endl;
    cout << numWays(1) << endl;
    cout << numWays(2) << endl;
    cout << numWays(7) << endl;
    cout << numWays(95) << endl;

    return 0;
}
