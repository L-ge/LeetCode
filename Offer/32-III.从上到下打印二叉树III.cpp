#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> vecRet;
    if(nullptr == root)
        return vecRet;

    vector<int> vecRetLine;
    int nCurLine = 0;
    int nCurLineTmp = 0;
    queue<pair<TreeNode*, int> > qCache;
    qCache.push(make_pair(root, nCurLine));
    while(qCache.size() > 0)
    {
        TreeNode* pFront = qCache.front().first;
        if(nCurLineTmp == qCache.front().second)
        {
            vecRetLine.push_back(pFront->val);
        }
        else
        {
            vecRet.push_back(vecRetLine);
            vecRetLine.clear();
            nCurLineTmp = qCache.front().second;
            vecRetLine.push_back(pFront->val);
        }

        qCache.pop();

        nCurLine = nCurLineTmp+1;
        if(nullptr != pFront->left)
            qCache.push(make_pair(pFront->left, nCurLine));
        if(nullptr != pFront->right)
            qCache.push(make_pair(pFront->right, nCurLine));
    }
    if(vecRetLine.size() > 0)
    {
        vecRet.push_back(vecRetLine);
        vecRetLine.clear();
    }

    // 相对于正常打印和Z字形打印，直接在这里做一下处理就算了
    vector<vector<int>> vecRetPrefix;
    int i=0;
    for(const auto& itemLine : vecRet)
    {
        if(0 == i % 2)
        {
            vector<int> vecRetLineTmp;
            for(const auto& itemTmp : itemLine)
            {
                vecRetLineTmp.push_back(itemTmp);
            }
            vecRetPrefix.push_back(vecRetLineTmp);
        }
        else
        {
            vector<int> vecRetLineTmp;
            for(auto itemTmp=itemLine.rbegin(); itemTmp!=itemLine.rend(); ++itemTmp)
            {
                vecRetLineTmp.push_back(*itemTmp);
            }
            vecRetPrefix.push_back(vecRetLineTmp);
        }
        ++i;
    }
    return vecRetPrefix;
}

int main(int argc, char** argv)
{
    TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);

    vector<vector<int>> vecRet = levelOrder(t1);
    for(const auto& item : vecRet)
    {
        for(const auto& itemTmp : item)
        {
            cout << itemTmp << "\t";
        }
        cout << endl;
    }

    cout << "\n---------------------\n";

    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);
    t2->left->left = new TreeNode(4);
    t2->right->right = new TreeNode(5);

    vector<vector<int>> vecRet2 = levelOrder(t2);
    for(const auto& item : vecRet2)
    {
        for(const auto& itemTmp : item)
        {
            cout << itemTmp << "\t";
        }
        cout << endl;
    }

    return 0;
}
