#include <iostream>
#include <vector>

using namespace std;

vector<int> exchange(vector<int>& nums)
{
    // 两个下标A和B，下标A遇到一个偶数，就停止，等B下标遇到一个奇数就交换
    if(nums.size() <= 1)
    {
        return nums;
    }
    int nIndexA = 0;
    int nIndexB = nIndexA+1;
    while(nIndexB < nums.size())
    {
        while(nIndexA< nums.size() && 1 == nums[nIndexA] % 2)       // 奇数的时候就一直往后面找
        {
            ++nIndexA;
        }
        if(nIndexA >= nums.size())
        {
            break;
        }

        // 现在nIndexA指向的是一个偶数，则nIndexB在nIndexA后面找
        nIndexB = nIndexA+1;
        while(nIndexB < nums.size() && 0 == nums[nIndexB] % 2)
        {
            ++nIndexB;
        }
        if(nIndexB >= nums.size())
        {
            break;
        }

        // 现在nIndexB指向的是一个奇数，则交换A和B的值
        int nTmp = nums[nIndexA];
        nums[nIndexA] = nums[nIndexB];
        nums[nIndexB] = nTmp;
        ++nIndexA;
        nIndexB = nIndexA+1;
    }
    return nums;
}

int main(int argc, char** argv)
{
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums11 = exchange(nums1);
    for(const auto& item : nums11)
        cout << item << endl;

    return 0;
}
