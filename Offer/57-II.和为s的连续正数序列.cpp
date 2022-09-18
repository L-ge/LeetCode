#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> findContinuousSequence(int target)
{
    vector<vector<int>> vecResult;
    // 连续正数序列，因此起始值是1、2...
    int nSmall = 1;
    int nBig = 2;
    // 因为至少有两个值，比如要找9，那么nMid=5，4+5=9.因此4,5已经是最短的序列了，再往前找也找不到了
    int nMid = (1 + target) / 2;
    int nCurSum = nSmall + nBig;
    while(nSmall < nMid)
    {
        if(nCurSum == target)
        {
            vector<int> vecTmp;
            for(int i=nSmall; i<=nBig; ++i)
                vecTmp.push_back(i);
            vecResult.push_back(vecTmp);
        }

        // 当前和已经很大了，那么要减掉前面的small看看
        while(nCurSum > target && nSmall < nMid)
        {
            nCurSum -= nSmall;
            ++nSmall;

            // 再判断一下，此时相等了没
            if(nCurSum == target)
            {
                vector<int> vecTmp;
                for(int i=nSmall; i<=nBig; ++i)
                    vecTmp.push_back(i);
                vecResult.push_back(vecTmp);
            }
        }

        // 当前和还不够大，因此加个nBig看看
        ++nBig;
        nCurSum += nBig;
    }

    return vecResult;
}

int main(int argc, char** argv)
{
    vector<vector<int>> vecResult = findContinuousSequence(9);
    for(auto itemVec : vecResult)
    {
        for(auto itemVec : itemVec)
            cout << itemVec << ",";
        cout << endl;
    }

    return 0;
}
