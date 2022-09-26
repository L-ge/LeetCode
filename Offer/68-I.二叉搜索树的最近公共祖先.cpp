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
    // 递归
    if(nullptr == root)
        return nullptr;
    if(root->val > p->val && root->val > q->val)    // 当前结点的值比它俩的值都大，那看看左子树
        return lowestCommonAncestor(root->left, p, q);
    if(root->val < p->val && root->val < q->val)    // 当前结点的值比它俩的值都小，那看看右子树
        return lowestCommonAncestor(root->right, p, q);

    // 到这里，也就是p，q在当前结点的两边，当前结点就是最近公共祖先
    return root;
}

int main(int argc, char** argv)
{

    return 0;
}
