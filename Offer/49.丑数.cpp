#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n)
{
    // 暴力解会超时
    vector<int> vecUglyNumSequence;     // 就是第i个丑数是啥
    vecUglyNumSequence.resize(n);
    vecUglyNumSequence[0] = 1;          // 第0个丑数是1
    int nIndexFromX2 = 0;   // 通过nIndexFromX2的丑数乘以2来获取下一个丑数
    int nIndexFromX3 = 0;   // 通过nIndexFromX3的丑数乘以3来获取下一个丑数
    int nIndexFromX5 = 0;   // 通过nIndexFromX5的丑数乘以5来获取下一个丑数
    for(int i=1; i<n; ++i)
    {
        int nNextUglyNumX2 = vecUglyNumSequence[nIndexFromX2] * 2;
        int nNextUglyNumX3 = vecUglyNumSequence[nIndexFromX3] * 3;
        int nNextUglyNumX5 = vecUglyNumSequence[nIndexFromX5] * 5;

        // 关键步骤：因为要求有序，因此取最小值
        vecUglyNumSequence[i] = min(min(nNextUglyNumX2, nNextUglyNumX3), nNextUglyNumX5);

        // 取了哪个值，那么下次就用下一个下标上的值*2来获取下一个丑数
        // 注意可能都相等的情况
        if(vecUglyNumSequence[i] == nNextUglyNumX2)
        {
            ++nIndexFromX2;
        }
        if(vecUglyNumSequence[i] == nNextUglyNumX3)
        {
            ++nIndexFromX3;
        }
        if(vecUglyNumSequence[i] == nNextUglyNumX5)
        {
            ++nIndexFromX5;
        }
    }

    return vecUglyNumSequence[n-1];
}

int main(int argc, char** argv)
{
    cout << nthUglyNumber(10) << endl;

    return 0;
}
