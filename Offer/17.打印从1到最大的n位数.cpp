#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> printNumbers(int n)
{
    int nBigest = pow(10, n);
    vector<int> vec;
    for(int i=1; i<nBigest; ++i)
    {
        vec.push_back(i);
    }
    return vec;
}

int main(int argc, char** argv)
{
    vector<int> vec = printNumbers(2);
    for(const auto& item : vec)
        cout << item << endl;

    return 0;
}
