#include <iostream>
#include <vector>

using namespace std;

int countDigitOne(int n)
{
    // 分别统计个位、十位、百位...中1出现的次数，再求和
    int nResult = 0;
    for(long long nBase=1; nBase<=n; nBase *= 10)
    {
        // 当n=4321，nBase=100 时，
        int nBaseCntTotal = (int)(n / nBase);          // 有多少个base，此时nBaseCntTotal=43
        int nBaseLeft = (int)(n % nBase);              // 剩下多少尾数，此时nCurBaseNum=21
        int nBaseCntCur = nBaseCntTotal % 10;   // 当前数位上有多少个base，此时nBaseCntCur=3
        int nBaseCntHigh = nBaseCntTotal / 10;  // 高位有多少个base，此时nBaseCntTotal=4；这里是为了算当前位(也就是它的低位)有多少倍1

        if(nBaseCntCur > 1)
        {
            //              4321
            //              [4] 3 [21]
            // 变化范围：   [0-4] 3  [0-99]
            // 因此就是：   5    *   100
            nResult += (nBaseCntHigh+1)*nBase;
        }
        else if(nBaseCntCur == 1)   // 1已经是固定在本位了，所以当本位是1的时候，并没有全满1
        {
            //                   4121
            //                   [4] 1 [21]
            // 变化范围情况1：   [0-3] 1  [0-99]
            // 变化范围情况2：   [4]   1  [0-21]
            // 因此就是：        4    *   22     + 1 * (22+1)
            nResult += (nBaseCntHigh*nBase + (nBaseLeft + 1));
        }
        else        // 也就是为0的时候
        {
            //              4021
            //              [4] 0 [21]
            // 变化范围：   [0-3] 0  [0-99]
            // 因此就是：   4    *   100
            nResult += nBaseCntHigh*nBase;
        }
    }

    return nResult;
}

int main(int argc, char** argv)
{
    cout << countDigitOne(12) << endl;      // 5
    cout << countDigitOne(13) << endl;      // 6
    return 0;
}
