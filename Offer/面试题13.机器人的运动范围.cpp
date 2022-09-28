#include <iostream>
#include <vector>

using namespace std;

int sum(int x, int y)
{
    // [35, 37]£¬3+5+3+7=18
    int nRet=0;
    while(x)
    {
        nRet += x % 10;
        x /= 10;
    }
    while(y)
    {
        nRet += y % 10;
        y /= 10;
    }
    return nRet;
}

int movingCountImp(int m, int n, int k, int i, int j, vector<vector<bool>>& vecVisit)
{
    if(i < 0 || j < 0)
        return 0;
    if(i >= m || j >= n)
        return 0;
    if(true == vecVisit[i][j])
        return 0;
    if(sum(i, j) > k)
        return 0;
    vecVisit[i][j] = true;
    return 1
         + movingCountImp(m, n, k, i-1, j, vecVisit)
         + movingCountImp(m, n, k, i, j-1, vecVisit)
         + movingCountImp(m, n, k, i+1, j, vecVisit)
         + movingCountImp(m, n, k, i, j+1, vecVisit);
}

int movingCount(int m, int n, int k)
{
    vector<vector<bool>> vecVisit(m, vector<bool>(n));
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            vecVisit[i][j] = false;
    return movingCountImp(m, n, k, 0, 0, vecVisit);
}

int main(int argc, char** argv)
{
    cout << movingCount(2, 3, 1);
    return 0;
}
