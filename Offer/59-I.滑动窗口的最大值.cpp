#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    // 暴力会超时
    vector<int> vecResult;
    if(nums.size() >= k && k >= 1)
    {
        deque<int> qIndex;

        // 处理前k个数
        for(int i=0; i<k; ++i)
        {
            // 把小的元素pop掉
            while(false == qIndex.empty() && nums[i] >= nums[qIndex.back()])
                qIndex.pop_back();
            qIndex.push_back(i);
        }

        for(int i=k; i<nums.size(); ++i)
        {
            vecResult.push_back(nums[qIndex.front()]);
            // 把小的元素pop掉
            while(false == qIndex.empty() && nums[i] >= nums[qIndex.back()])
                qIndex.pop_back();
            //队列头部的数字已经从窗口划出，那么滑出的数字也需要从队列的头部删除
            if(false == qIndex.empty() && qIndex.front() <= i-k)
                qIndex.pop_front();
            qIndex.push_back(i);
        }
        vecResult.push_back(nums[qIndex.front()]);
    }

    return vecResult;
}

int main(int argc, char** argv)
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> ret = maxSlidingWindow(nums, 3);
    for(const auto item : ret)
        cout << item << ", ";

    return 0;
}
