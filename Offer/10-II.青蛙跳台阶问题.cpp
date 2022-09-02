#include <iostream>
#include <stack>

using namespace std;

int numWays(int n)
{
    // Ҳ����쳲���������
    // ���磬��һ����һ������ôʣ������Ϊ n-1 ��̨�׵���������һ������������ôʣ������Ϊ n-2 ��̨�׵�����...
    // Ҳ�� f(n) = f(n-1) + f(n-2)
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
