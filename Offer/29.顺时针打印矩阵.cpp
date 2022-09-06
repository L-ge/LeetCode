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

    // ��������ȡԪ�أ�Ҳ����ȦȦ���Ϸ�
    for(int i=nStartPoint; i<=nColEnd; ++i)
    {
        vecResult.push_back(matrix[nStartPoint][i]);
    }

    // �������£�Ҳ����ȦȦ���ұ�
    for(int i=nStartPoint+1; i<=nRowEnd; ++i)
    {
        vecResult.push_back(matrix[i][nColEnd]);
    }

    // ����ֻ��һ�е�ʱ�򣬴�����������������ظ�������������������ϵ����

    if(nStartPoint < nRowEnd)
    {
        // ��������Ҳ����ȦȦ���·�
        for(int i=nColEnd-1; i>=nStartPoint; --i)
        {
            vecResult.push_back(matrix[nRowEnd][i]);
        }
    }

    if(nStartPoint < nRowEnd-1 && nStartPoint < nColEnd)
    {
        // �������ϣ�Ҳ����ȦȦ�����
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
