#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> levelOrder(TreeNode* root)
{
    vector<int> vecRet;
    // 其实就是当前节点进队列，然后左右子树进队列，然后取出队列首个结点压到vector里面去，
    // 然后取出左节点，如果左节点有子树，则再进队列，然后将左节点压到vector里面去...

    if(nullptr == root)
        return vecRet;
    queue<TreeNode*> qCache;
    qCache.push(root);
    while(qCache.size() > 0)
    {
        TreeNode* pFront = qCache.front();
        qCache.pop();
        vecRet.push_back(pFront->val);
        if(nullptr != pFront->left)
            qCache.push(pFront->left);
        if(nullptr != pFront->right)
            qCache.push(pFront->right);
    }
    return vecRet;
}

int main(int argc, char** argv)
{
    TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);

    vector<int> vecRet = levelOrder(t1);
    for(const auto& item : vecRet)
        cout << item << endl;

    return 0;
}
