#include <iostream>
#include <map>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
    // 二分查找
    if(0 == nums.size())
        return -1;
    int nLeft = 0;
    int nRight = nums.size()-1;
    while(nLeft <= nRight)
    {
        int nMid = (nLeft + nRight) / 2;
        if(nums[nMid] != nMid)
        {
            if(0 == nMid || nums[nMid-1] == nMid-1)
                return nMid;
            // 上面的条件不成立，因此右边肯定没问题
            nRight = nMid - 1;
        }
        else
        {
            // 即nums[nMid] == nMid，所以左边肯定没问题
            nLeft = nMid + 1;
        }
    }

    // 要考虑那个数正好是缺的那个最后的数的情况
    if(nLeft == nums.size())
        return nums.size();
    return -1;
}

int main(int argc, char** argv)
{

    return 0;
}
