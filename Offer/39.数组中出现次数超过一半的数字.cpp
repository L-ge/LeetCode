#include <iostream>
#include <vector>
#include <map>

using namespace std;

int majorityElement(vector<int>& nums)
{
    map<int, int> mpCacheCount;
    for(const auto item : nums)
    {
        if(mpCacheCount.count(item) > 0)
        {
            ++mpCacheCount[item];
        }
        else
        {
            mpCacheCount[item] = 1;
        }
    }

    for(const auto item : mpCacheCount)
    {
        if(item.second > nums.size() / 2)
        {
            return item.first;
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    vector<int> vec = {1,2,3,2,2,2,5,4,2};
    cout << majorityElement(vec) << endl;

    return 0;
}
