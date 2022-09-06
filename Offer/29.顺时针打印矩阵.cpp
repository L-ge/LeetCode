#include <iostream>
#include <vector>

using namespace std;

vector<int> getOneCircle(vector<vector<int>>& matrix, int nStartPoint)
{
    vector<int> vecResult;

    int nRow = matrix.size();
    int nCol = matrix[0].size();
    int nRowEnd = nRow - 1 - nStartPoint;
    int nColEnd = nCol - 1 - nStartPoint;

    // 从左往右取元素，也就是圈圈的上方
    for(int i=nStartPoint; i<=nColEnd; ++i)
    {
        vecResult.push_back(matrix[nStartPoint][i]);
    }

    // 从上往下，也就是圈圈的右边
    for(int i=nStartPoint+1; i<=nRowEnd; ++i)
    {
        vecResult.push_back(matrix[i][nColEnd]);
    }

    // 考虑只有一行的时候，从右往左与从左往右重复、从上往下与从下往上的情况

    if(nStartPoint < nRowEnd)
    {
        // 从右往左，也就是圈圈的下方
        for(int i=nColEnd-1; i>=nStartPoint; --i)
        {
            vecResult.push_back(matrix[nRowEnd][i]);
        }
    }

    if(nStartPoint < nRowEnd-1 && nStartPoint < nColEnd)
    {
        // 从下往上，也就是圈圈的左边
        for(int i=nRowEnd-1; i>=nStartPoint+1; --i)
        {
            vecResult.push_back(matrix[i][nStartPoint]);
        }
    }

    return vecResult;
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    if(matrix.size() > 0 && matrix[0].size() > 0)
    {
        vector<int> vecResult;
        int nStartPoint = 0;
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        while(nRow > nStartPoint * 2 && nCol > nStartPoint * 2)
        {
            vector<int> vecTmp = getOneCircle(matrix, nStartPoint);
            vecResult.insert(vecResult.end(), vecTmp.begin(), vecTmp.end());
            ++nStartPoint;
        }
        return vecResult;
    }
    return vector<int>();
}

int main(int argc, char** argv)
{
    return 0;
}
