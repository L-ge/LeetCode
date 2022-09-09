#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> getLeastNumbers(vector<int>& arr, int k)
{
    if(0 == arr.size() || 0 == k)
        return {};

    // 利用 multiset 来实现，如果 multiset 满了，此时如果再插入，
    // 就与最大的元素比较，如果比最大的元素小，就弹出最大的元素，压它进去
    multiset<int> msetCache;
    for(const auto item : arr)
    {
        if(msetCache.size() < k)
        {
            msetCache.insert(item);
        }
        else
        {
            auto needDelItem = --msetCache.end();
            if(item < *needDelItem)
            {
                msetCache.erase(needDelItem);
                msetCache.insert(item);
            }
        }
    }

    vector<int> vecRet;
    for(const auto item : msetCache)
    {
        vecRet.push_back(item);
    }
    return vecRet;
}

int main(int argc, char** argv)
{
    vector<int> vec = {3,2,1};
    vector<int> vecRet = getLeastNumbers(vec, 2);
    for(const auto item : vecRet)
        cout << item << endl;

    return 0;
}
