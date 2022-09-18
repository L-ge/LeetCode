#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    if(nums.size() <= 0)
        return {};

    int nIndexStart = 0;
    int nIndexEnd = nums.size()-1;
    while(nIndexStart <= nIndexEnd)
    {
        // ��Ϊnums������ģ����ʹ���������м俿£�ķ���
        long long nCurSum = nums[nIndexStart] + nums[nIndexEnd];
        if(nCurSum == target)
        {
            vector<int> vecTmp;
            vecTmp.push_back(nums[nIndexStart]);
            vecTmp.push_back(nums[nIndexEnd]);
            return std::move(vecTmp);
        }
        else if(nCurSum > target)
        {
            --nIndexEnd;
        }
        else
        {
            ++nIndexStart;
        }
    }
    return {};
}

int main(int argc, char** argv)
{

    return 0;
}
