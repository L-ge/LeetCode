#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    // ��̬�滮���
    vector<int> vecMaxSum;
    vecMaxSum.resize(nums.size());
    vecMaxSum[0] = nums[0];
    for(int i=1; i<nums.size(); ++i)
    {
        // ���ǰ��ֵ���ܺͼ��ϵ�ǰֵ���ȵ�ǰֵҪ��
        // ����Ϊ��ǰֵ���ܺ;���ǰ��ֵ���ܺͼ��ϵ�ǰֵ��
        // ������Ϊ��ǰֵ���ܺ;��ǵ�ǰֵ��
        if(vecMaxSum[i-1] + nums[i] > nums[i])
        {
            vecMaxSum[i] = vecMaxSum[i-1] + nums[i];
        }
        else
        {
            vecMaxSum[i] = nums[i];
        }
    }

    // �ҳ������Ǹ�ֵ
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
