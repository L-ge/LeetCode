#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    // 动态规划求解
    vector<int> vecMaxSum;
    vecMaxSum.resize(nums.size());
    vecMaxSum[0] = nums[0];
    for(int i=1; i<nums.size(); ++i)
    {
        // 如果前面值的总和加上当前值，比当前值要大，
        // 则认为当前值的总和就是前面值的总和加上当前值。
        // 否则，认为当前值的总和就是当前值。
        if(vecMaxSum[i-1] + nums[i] > nums[i])
        {
            vecMaxSum[i] = vecMaxSum[i-1] + nums[i];
        }
        else
        {
            vecMaxSum[i] = nums[i];
        }
    }

    // 找出最大的那个值
    int nMaxSum = vecMaxSum[0];
    for(int i=1; i<vecMaxSum.size(); ++i)
    {
        //cout << vecMaxSum[i] <<endl;
        if(vecMaxSum[i] > nMaxSum)
            nMaxSum = vecMaxSum[i];
    }
    return nMaxSum;
}

int main(int argc, char** argv)
{
    vector<int> vec{-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(vec) << endl;
    return 0;
}
