#include <iostream>

using namespace std;

int hammingWeight(uint32_t n)
{
    int nCnt = 0;
    while(n)
    {
        if(n & 0x01)
            ++nCnt;
        n = n >> 1;
    }
    return nCnt;
}

int main(int argc, char** argv)
{
    cout << hammingWeight(11) << endl;
    cout << hammingWeight(128) << endl;
    cout << hammingWeight(4294967293) << endl;

    return 0;
}
