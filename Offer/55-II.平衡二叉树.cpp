#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root)
{
    if(nullptr == root)
        return 0;
    int nDepthLeft = maxDepth(root->left);
    int nDepthRight = maxDepth(root->right);

    int nDepthCur = max(nDepthLeft, nDepthRight) + 1;
    return nDepthCur;
}

bool isBalanced(TreeNode* root)
{
    if(nullptr == root)
        return true;
    int nDepthLeft = maxDepth(root->left);
    int nDepthRight = maxDepth(root->right);

    if(nDepthLeft - nDepthRight > 1 || nDepthRight - nDepthLeft > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

int main(int argc, char** argv)
{

    return 0;
}
