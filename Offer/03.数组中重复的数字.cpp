#include <iostream>
#include <vector>

using namespace std;

int findRepeatNumber(vector<int>& nums)
{
    for(int i=0; i<nums.size(); ++i)
    {
        // 如果i位置上的数字不是i，那num[i]位置的元素与i位置上的元素交换
        while(nums[i] != i)
        {
            // 如果i位置上的数字不是i，但num[i]位置上的元素已经是num[i]了，那么就是有重复
            if(nums[nums[i]] == nums[i])
            {
                return nums[nums[i]];
            }
            int nTmp = nums[i];
            nums[i] = nums[nTmp];
            nums[nTmp] = nTmp;
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    cout << findRepeatNumber(nums);
    return 0;
}
