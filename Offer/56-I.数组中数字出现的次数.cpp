#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumbers(vector<int>& nums)
{
    // 利用异或，同0异1的特点
    // 这里是其他数字都出现了两次；相同的数字异或就是0。

    int nAllNumXOR = 0;
    for(const auto item : nums)
        nAllNumXOR ^= item;

    // 在这个异或的结果中，二进制表示中，找到一个1
    unsigned int nIndexBit1 = 0;
    while((nAllNumXOR & 1) == 0 && (nIndexBit1 < 8*sizeof(int)))
    {
        nAllNumXOR = nAllNumXOR >> 1;
        ++nIndexBit1;
    }

    // 经过一个循环之后，nNeedFindNum1 就是第 nIndexBit1 位是1 的那个数；
    // 而异或完，第 nIndexBit1 位不是1 的那个数就是另外要找的那个数。
    int nNeedFindNum1 = 0;
    int nNeedFindNum2 = 0;
    for(const auto item : nums)
    {
        // 找到一个数，它的二进制表示中，第 nIndexBit1 位是1
        int nTmp = item >> nIndexBit1;
        if(nTmp & 1)
        {
            nNeedFindNum1 ^= item;
        }
        else
        {
            nNeedFindNum2 ^= item;
        }
    }
    return {nNeedFindNum1, nNeedFindNum2};
}

int main(int argc, char** argv)
{

    return 0;
}
