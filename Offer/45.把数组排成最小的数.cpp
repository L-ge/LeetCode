#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string minNumber(vector<int>& nums)
{
    vector<string> vecCache;
    for(const auto item : nums)
    {
        vecCache.push_back(to_string(item));
    }
    sort(vecCache.begin(), vecCache.end(),
         [](const string& s1, const string& s2)
         {
            // 不知道为什么可以，看别人数学证明的
            return s1+s2 < s2+s1;
         });
    string sRet;
    for(const auto item : vecCache)
    {
        sRet.append(item);
    }
    return sRet;
}

int main(int argc, char** argv)
{
    vector<int> nums = {10,2};
    cout << minNumber(nums) << endl;
    return 0;
}
