#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<double> dicesProbability(int n)
{
    vector<double> vecDP(6, 1.0/6.0);
    for(int i=2; i<=n; ++i)
    {
        vector<double> vecTmp(5*i+1, 0);
        for(int j=0; j<vecDP.size(); ++j)
        {
            for(int k=0; k<6; ++k)
            {
                vecTmp[j+k] += vecDP[j] / 6.0;
            }
        }
        vecDP = vecTmp;
    }
    return vecDP;
}

int main(int argc, char** argv)
{
    vector<double> ret = dicesProbability(2);
    for(const auto item : ret)
        cout << item << ", ";

    return 0;
}
