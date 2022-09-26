#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(nullptr == root)
        return nullptr;

    if(root == p || root == q)
        return root;
    TreeNode* pLeft = lowestCommonAncestor(root->left, p, q);
    TreeNode* pRight = lowestCommonAncestor(root->right, p, q);

    // 如果pLeft和pRight都不为空，则p、q分别在当前结点的左右两边
    if(nullptr != pLeft && nullptr != pRight)
        return root;
    // p、q都在当前结点的左子树
    if(nullptr != pLeft)
        return pLeft;
    // p、q都在当前结点的右子树
    if(nullptr != pRight)
        return pRight;
    return nullptr;
}

int main(int argc, char** argv)
{

    return 0;
}
