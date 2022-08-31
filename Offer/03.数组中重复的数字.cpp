#include <iostream>
#include <vector>

using namespace std;

int findRepeatNumber(vector<int>& nums)
{
    for(int i=0; i<nums.size(); ++i)
    {
        // ���iλ���ϵ����ֲ���i����num[i]λ�õ�Ԫ����iλ���ϵ�Ԫ�ؽ���
        while(nums[i] != i)
        {
            // ���iλ���ϵ����ֲ���i����num[i]λ���ϵ�Ԫ���Ѿ���num[i]�ˣ���ô�������ظ�
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
