#include <iostream>
#include <vector>
#include <map>

using namespace std;

int singleNumber(vector<int>& nums)
{
    // ûҪ��ռ临�Ӷȣ�����map��
    map<int, int> mpCache;
    for(const auto item : nums)
    {
        if(mpCache.count(item) > 0)
            ++mpCache[item];
        else
            mpCache[item] = 1;
    }

    for(const auto item : mpCache)
    {
        if(1 == item.second)
            return item.first;
    }
    return -1;
}

int main(int argc, char** argv)
{

    return 0;
}
