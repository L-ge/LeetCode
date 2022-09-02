#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool existImp(vector<vector<char>>& vecBoard,
              string sWord, int& nIndexWord,
              int nRow, int nCol,
              vector<vector<bool>>& vecFlag)
{
    if(nIndexWord >= sWord.length())    // �Ѿ������һ���ַ��ˣ����ټ���ƥ�䣬����true
    {
        return true;
    }

    if(nRow >=0 && nRow < vecBoard.size()              // ��ֹ������Խ��
        && nCol >= 0 && nCol < vecBoard[0].size()      // ��ֹ������Խ��
        && nIndexWord < sWord.length()                  // ��ֹ�ַ����±�Խ��
        && vecBoard[nRow][nCol] == sWord[nIndexWord]    // ��ǰ�ڵ��ַ�ƥ��
        && false == vecFlag[nRow][nCol])                // ��ǰ�ڵ�û�б����ʹ�
    {
        ++nIndexWord;       // ������һ���ַ������±��ƶ�һλ
        vecFlag[nRow][nCol] = true;

        // ���ݷ�����������һ���ڵ�
        bool bHasExist =
            existImp(vecBoard, sWord, nIndexWord, nRow, nCol-1, vecFlag)        // ��ڵ�
         || existImp(vecBoard, sWord, nIndexWord, nRow, nCol+1, vecFlag)        // �ҽڵ�
         || existImp(vecBoard, sWord, nIndexWord, nRow-1, nCol, vecFlag)        // �Ͻڵ�
         || existImp(vecBoard, sWord, nIndexWord, nRow+1, nCol, vecFlag);       // �½ڵ�

        if(false == bHasExist)      // ����������Ҷ�û�У���Ҫ����
        {
            --nIndexWord;
            vecFlag[nRow][nCol] = false;
        }
        else
        {
            return true;
        }
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word)
{
    // ��ʼ��������飬�Ա��ڱ�ǵ�ǰ�ڵ��Ƿ��Ѿ����ʹ�
    vector<vector<bool>> vecFlag;
    for(int i=0; i<board.size(); ++i)
    {
        vector<bool> vecFlagTmp;
        for(int j=0; j<board[i].size(); ++j)
        {
            vecFlagTmp.push_back(false);
        }
        vecFlag.push_back(std::move(vecFlagTmp));
    }

    int nIndexWord = 0;
    for(int i=0; i<board.size(); ++i)
    {
        for(int j=0; j<board[i].size(); ++j)
        {
            if(existImp(board, word, nIndexWord, i, j, vecFlag))
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv)
{
    vector<vector<char>> test1{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> test2{{'a','b'},{'c','d'}};
    vector<vector<char>> test3{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

    cout << exist(test1, "ABCCED") << endl;
    cout << exist(test2, "abcd") << endl;
    cout << exist(test3, "SEE") << endl;

    return 0;
}
