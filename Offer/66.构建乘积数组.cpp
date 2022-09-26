#include <iostream>
#include <vector>

using namespace std;

vector<int> constructArr(vector<int>& a)
{
    if(0 == a.size())
        return {};
    vector<int> vecB(a.size(), 1);

    // B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]
    // 分成两部分，A[0]×A[1]×…×A[i-1] 和 A[i+1]×…×A[n-1]
    vecB[0] = 1;
    for(int i=1; i<a.size(); ++i)
    {
        vecB[i] = vecB[i-1] * a[i-1];
    }

    int nTmp = 1;
    for(int i=a.size()-2; i>=0; --i)
    {
        nTmp *= a[i+1];
        vecB[i] *= nTmp;
    }
    return vecB;
}

int main(int argc, char** argv)
{

    return 0;
}
