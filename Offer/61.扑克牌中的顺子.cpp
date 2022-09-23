#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isStraight(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int nMin = INT_MAX;
    int nMax = INT_MIN;
    int nPre = 0;
    for(const auto i : nums)
    {
        if(0 == i)
            continue;
        if(nPre == i)
            return false;
        nMin = min(nMin, i);
        nMax = max(nMax, i);
        nPre = i;
    }
    return nMax - nMin < 5 ? true : false;
}

int main(int argc, char** argv)
{
    vector<int> nums{1,2,3,4,5};
    cout << isStraight(nums) << endl;

    return 0;
}
