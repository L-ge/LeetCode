#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeImp(vector<int>& vecPreOrder, vector<int>& vecInOrder,
                       int nPreOrderLeft, int nPreOrderRight,
                       int nInOrderLeft, int nInOrderRight)
{
    if(nPreOrderLeft > nPreOrderRight || nInOrderLeft > nInOrderRight)
        return nullptr;

    // 在中序遍历找到根节点，这样的话就可以分割左右子树了
    int nRootIndexInOrder = nInOrderLeft;
    while(nRootIndexInOrder <= nPreOrderRight
          && vecInOrder[nRootIndexInOrder] != vecPreOrder[nPreOrderLeft])
    {
        ++nRootIndexInOrder;
    }

    // 根据“前序遍历的第一个元素为根节点”构建根节点
    TreeNode* pRoot = new TreeNode(vecPreOrder[nPreOrderLeft]);
    // 左子树的节点个数
    int nCntLeft = nRootIndexInOrder - nInOrderLeft;
    // 右子树的节点个数
    int nCntRight = nInOrderRight - nRootIndexInOrder;
    // 递归构建左子树
    pRoot->left = buildTreeImp(vecPreOrder, vecInOrder, nPreOrderLeft+1, nPreOrderLeft+nCntLeft, nInOrderLeft, nRootIndexInOrder-1);
    // 递归构建右子树
    pRoot->right = buildTreeImp(vecPreOrder, vecInOrder, nPreOrderLeft+nCntLeft+1, nPreOrderRight, nRootIndexInOrder+1, nInOrderRight);

    return pRoot;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    return buildTreeImp(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}

int main(int argc, char** argv)
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    cout << buildTree(preorder, inorder)->val;

    return 0;
}
