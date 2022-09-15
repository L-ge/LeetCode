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

int main(int argc, char** argv)
{

    return 0;
}
