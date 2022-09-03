#include <iostream>
#include <vector>

using namespace std;

int cuttingRope(int n)
{
    // 使用动态规划方法求解
    if(n == 2)          // 1*1
        return 1;
    if(n == 3)          // 1*2
        return 2;

    vector<int> vecWay;
    vecWay.resize(n+1);

    // 初始化下面几个特殊的，因为它单独的时候是上面特判的那些值，
    // 而分解的时候可以是更大的值，比如3，单独时是1*2；分解时是3
    vecWay[0] = 0;
    vecWay[1] = 1;
    vecWay[2] = 2;
    vecWay[3] = 3;

    for(int i=4; i<=n; ++i)
    {
        int nMaxValue = 0;
        // j是从1开始，因为0就是不管了，就是i它自己，不用再分解
        for(int j=1; j<=i/2; ++j)   // 一直算到i/2就行，因为后面都是重复的
        {
            int nValueTmp = vecWay[j] * vecWay[i-j];
            if(nValueTmp > nMaxValue)
                nMaxValue = nValueTmp;
            vecWay[i] = nMaxValue;
        }
    }

    return vecWay[n];
}

int main(int argc, char** argv)
{
    cout << cuttingRope(2) << endl;
    cout << cuttingRope(10) << endl;

    return 0;
}
