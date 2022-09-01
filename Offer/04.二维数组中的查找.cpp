#include <iostream>
#include <vector>

using namespace std;


bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
    if(matrix.size() > 0 && matrix[0].size() > 0)
    {
        int nRow = 0;
        int nColumn = matrix[0].size() - 1;

        // �Ǵ����Ͻǿ�ʼ��������Ǵ�0��ʼ�����Ǵ�����ֵ��ʼ
        while(nRow < matrix.size() && nColumn >= 0)
        {
            if(matrix[nRow][nColumn] == target)
            {
                return true;
            }
            else if(matrix[nRow][nColumn] > target)
            {
                --nColumn;      // �����ܳ����ڵ�ǰ�У���Ϊ��ǰ�����Ͻǵ�ֵ���Ǹ��е���Сֵ����˰ѵ�ǰ���޳���
            }
            else    // ���ڵ����
            {
                ++nRow;          //  �϶����ڵ�ǰ���ˣ���Ϊ��ǰ�����Ͻǵ�ֵ���Ǹ��е����ֵ����˰ѵ�ǰ���޳���
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
