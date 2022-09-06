#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mirrorTree(TreeNode* root)
{
    if(nullptr == root)
        return nullptr;

    TreeNode* pMirror = root;
    TreeNode* pRootLeft = root->left;
    TreeNode* pRootRight = root->right;
    pMirror->left = mirrorTree(pRootRight);
    pMirror->right = mirrorTree(pRootLeft);
    return pMirror;
}

int main(int argc, char** argv)
{
    TreeNode* t1 = new TreeNode(4);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(7);
    t1->left->left = new TreeNode(1);
    t1->left->right = new TreeNode(3);
    t1->right->left = new TreeNode(6);
    t1->right->right = new TreeNode(9);

    TreeNode* ret = mirrorTree(t1);
    cout << ret->val << endl;
    cout << ret->left->val << endl;
    cout << ret->right->val << endl;
    cout << ret->left->left->val << endl;
    cout << ret->left->right->val << endl;
    cout << ret->right->left->val << endl;
    cout << ret->right->right->val << endl;

    return 0;
}
