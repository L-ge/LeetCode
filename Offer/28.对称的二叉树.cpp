#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetricSubTree(TreeNode* pTreeLeft, TreeNode* pTreeRight)
{
    if(nullptr == pTreeLeft && nullptr == pTreeRight)
        return true;
    if(nullptr == pTreeLeft && nullptr != pTreeRight)
        return false;
    if(nullptr != pTreeLeft && nullptr == pTreeRight)
        return false;

    if(pTreeLeft->val != pTreeRight->val)
        return false;
    return isSymmetricSubTree(pTreeLeft->left, pTreeRight->right)
        && isSymmetricSubTree(pTreeLeft->right, pTreeRight->left);
}

bool isSymmetric(TreeNode* root)
{
    if(nullptr == root)
        return true;

    if(nullptr == root->left && nullptr == root->right)
        return true;

    return isSymmetricSubTree(root->left, root->right);
}

int main(int argc, char** argv)
{
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(3);
    t1->left->right = new TreeNode(4);
    t1->right->left = new TreeNode(4);
    t1->right->right = new TreeNode(3);

    TreeNode* t2 = new TreeNode(1);
    t2->left = nullptr;
    t2->right = new TreeNode(2);
    cout << isSymmetric(t1) << endl;
    cout << isSymmetric(t2) << endl;
    return 0;
}
