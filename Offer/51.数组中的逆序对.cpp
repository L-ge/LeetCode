#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
int reversePairsImp(vector<int>& vecNum, int nStart, int nEnd, vector<int>& vecTmp)
{
    if(nStart == nEnd)
    {
        vecTmp[nStart] = vecNum[nStart];
        return 0;
    }

    int nLength = (nEnd-nStart) / 2;
    int nLeft = reversePairsImp(vecTmp, nStart, nStart+nLength, vecNum);    // 注意这里第一参数和最后一个参数
    int nRight = reversePairsImp(vecTmp, nStart+nLength+1, nEnd, vecNum);   // 注意这里第一参数和最后一个参数

    // 合并排序后的结果
    int nLeftLastIndex = nStart+nLength;
    int nRightLastIndex = nEnd;
    int nIndexTmp = nEnd;
    int nCount = 0;
    while(nLeftLastIndex >= nStart && nRightLastIndex >= nStart+nLength+1)
    {
        if(vecNum[nLeftLastIndex] > vecNum[nRightLastIndex])
        {
            vecTmp[nIndexTmp--] = vecNum[nLeftLastIndex--];
            nCount += nRightLastIndex - nStart - nLength;
        }
        else
        {
            vecTmp[nIndexTmp--] = vecNum[nRightLastIndex--];
        }
    }

    for(; nLeftLastIndex>=nStart; --nLeftLastIndex)
        vecTmp[nIndexTmp--] = vecNum[nLeftLastIndex];
    for(; nRightLastIndex>=nStart+nLength+1; --nRightLastIndex)
        vecTmp[nIndexTmp--] = vecNum[nRightLastIndex];
    return nLeft+nRight+nCount;
}

int reversePairs(vector<int>& nums)
{
    // 归并排序的思想
    if(0 == nums.size())
        return 0;

    vector<int> vecTmp(nums.size());
    for(int i=0; i<nums.size(); ++i)
        vecTmp[i] = nums[i];

    return reversePairsImp(nums, 0, nums.size()-1, vecTmp);
}

int main(int argc, char** argv)
{
    vector<int> nums = {7, 5, 6, 4};
    cout << reversePairs(nums) << endl;

    return 0;
}
