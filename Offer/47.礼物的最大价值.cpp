#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxValue(vector<vector<int>>& grid)
{
    int nRow = grid.size();
    int nCol = grid[0].size();
    vector<vector<int>> vecWay(nRow, vector<int>(nCol));
    for(int i=0; i<nRow; ++i)
    {
        for(int j=0; j<nCol; ++j)
        {
            // 动态规划中，i=0、i=1...这些值是比较特殊，要作特殊处理
            // 因为它们是起始值
            if(0 == i && 0 == j)
            {
                vecWay[i][j] = grid[i][j];
            }
            else if(0 == i)     // 第一行
            {
                vecWay[i][j] = vecWay[i][j-1] + grid[i][j];
            }
            else if(0 == j)     // 第一列
            {
                vecWay[i][j] = vecWay[i-1][j] + grid[i][j];
            }
            else
            {
                // 因为它只能往下走或往右走
                // 因此取 [i-1][j] 和 [i][j-1] 的最大值
                vecWay[i][j] = max(vecWay[i-1][j], vecWay[i][j-1]) + grid[i][j];
            }
        }
    }
    return vecWay[nRow-1][nCol-1];
}

int main(int argc, char** argv)
{
    vector<vector<int>> grid =
    {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    cout << maxValue(grid);     // 12
    return 0;
}
