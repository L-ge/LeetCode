#include <iostream>
#include <vector>

using namespace std;


bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
    if(matrix.size() > 0 && matrix[0].size() > 0)
    {
        int nRow = 0;
        int nColumn = matrix[0].size() - 1;

        // 是从右上角开始，因此行是从0开始，列是从最大的值开始
        while(nRow < matrix.size() && nColumn >= 0)
        {
            if(matrix[nRow][nColumn] == target)
            {
                return true;
            }
            else if(matrix[nRow][nColumn] > target)
            {
                --nColumn;      // 不可能出现在当前列，因为当前最右上角的值就是该列的最小值，因此把当前列剔除掉
            }
            else    // 少于的情况
            {
                ++nRow;          //  肯定不在当前行了，因为当前最右上角的值就是该行的最大值，因此把当前行剔除掉
            }
        }
    }

    return false;
}

int main(int argc, char** argv)
{
    vector<vector<int>> vec{
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << findNumberIn2DArray(vec, 5);
    return 0;
}
