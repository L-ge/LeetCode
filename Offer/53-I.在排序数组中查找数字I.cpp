#include <iostream>
#include <map>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
    map<int, int> mapCount;
    for(const auto item : nums)
    {
        if(mapCount.count(item) > 0)
            ++mapCount[item];
        else
            mapCount[item] = 1;
    }
    return mapCount[target];
}

int main(int argc, char** argv)
{

    return 0;
}
