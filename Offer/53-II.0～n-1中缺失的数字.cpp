#include <iostream>
#include <map>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
    // ���ֲ���
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
            // ���������������������ұ߿϶�û����
            nRight = nMid - 1;
        }
        else
        {
            // ��nums[nMid] == nMid��������߿϶�û����
            nLeft = nMid + 1;
        }
    }

    // Ҫ�����Ǹ���������ȱ���Ǹ������������
    if(nLeft == nums.size())
        return nums.size();
    return -1;
}

int main(int argc, char** argv)
{

    return 0;
}
