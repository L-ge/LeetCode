#include <iostream>
#include <vector>

using namespace std;

vector<int> exchange(vector<int>& nums)
{
    // �����±�A��B���±�A����һ��ż������ֹͣ����B�±�����һ�������ͽ���
    if(nums.size() <= 1)
    {
        return nums;
    }
    int nIndexA = 0;
    int nIndexB = nIndexA+1;
    while(nIndexB < nums.size())
    {
        while(nIndexA< nums.size() && 1 == nums[nIndexA] % 2)       // ������ʱ���һֱ��������
        {
            ++nIndexA;
        }
        if(nIndexA >= nums.size())
        {
            break;
        }

        // ����nIndexAָ�����һ��ż������nIndexB��nIndexA������
        nIndexB = nIndexA+1;
        while(nIndexB < nums.size() && 0 == nums[nIndexB] % 2)
        {
            ++nIndexB;
        }
        if(nIndexB >= nums.size())
        {
            break;
        }

        // ����nIndexBָ�����һ���������򽻻�A��B��ֵ
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
