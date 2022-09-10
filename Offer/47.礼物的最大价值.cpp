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
            // ��̬�滮�У�i=0��i=1...��Щֵ�ǱȽ����⣬Ҫ�����⴦��
            // ��Ϊ��������ʼֵ
            if(0 == i && 0 == j)
            {
                vecWay[i][j] = grid[i][j];
            }
            else if(0 == i)     // ��һ��
            {
                vecWay[i][j] = vecWay[i][j-1] + grid[i][j];
            }
            else if(0 == j)     // ��һ��
            {
                vecWay[i][j] = vecWay[i-1][j] + grid[i][j];
            }
            else
            {
                // ��Ϊ��ֻ�������߻�������
                // ���ȡ [i-1][j] �� [i][j-1] �����ֵ
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
