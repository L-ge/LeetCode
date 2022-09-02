#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool existImp(vector<vector<char>>& vecBoard,
              string sWord, int& nIndexWord,
              int nRow, int nCol,
              vector<vector<bool>>& vecFlag)
{
    if(nIndexWord >= sWord.length())    // 已经是最后一个字符了，不再继续匹配，返回true
    {
        return true;
    }

    if(nRow >=0 && nRow < vecBoard.size()              // 防止行坐标越界
        && nCol >= 0 && nCol < vecBoard[0].size()      // 防止列坐标越界
        && nIndexWord < sWord.length()                  // 防止字符串下标越界
        && vecBoard[nRow][nCol] == sWord[nIndexWord]    // 当前节点字符匹配
        && false == vecFlag[nRow][nCol])                // 当前节点没有被访问过
    {
        ++nIndexWord;       // 命中了一个字符，则下标移动一位
        vecFlag[nRow][nCol] = true;

        // 回溯法继续查找下一个节点
        bool bHasExist =
            existImp(vecBoard, sWord, nIndexWord, nRow, nCol-1, vecFlag)        // 左节点
         || existImp(vecBoard, sWord, nIndexWord, nRow, nCol+1, vecFlag)        // 右节点
         || existImp(vecBoard, sWord, nIndexWord, nRow-1, nCol, vecFlag)        // 上节点
         || existImp(vecBoard, sWord, nIndexWord, nRow+1, nCol, vecFlag);       // 下节点

        if(false == bHasExist)      // 如果上下左右都没有，则要回退
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
    // 初始化标记数组，以便于标记当前节点是否已经访问过
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
