#include <iostream>
#include <vector>
#include <list>

using namespace std;

int maxProfit(vector<int>& prices)
{
    // 其实就是记住第i个数字前面的最小值，就可以知道当天的利润最大是多少
    if(prices.size() < 2)
        return 0;
    int nMinBefore = prices[0];             // 前面的最小值
    int nMaxDiff = prices[1] - nMinBefore;  // 最大利润
    for(int i=2; i<prices.size(); ++i)
    {
        if(prices[i-1] < nMinBefore)
            nMinBefore = prices[i-1];

        int nCurrentDiff = prices[i] - nMinBefore;
        if(nCurrentDiff > nMaxDiff)
            nMaxDiff = nCurrentDiff;
    }

    if(nMaxDiff < 0)
        nMaxDiff = 0;
    return nMaxDiff;
}

int main(int argc, char** argv)
{
    vector<int> prices = {7,6,4,3,1};
    cout << maxProfit(prices);
    return 0;
}
