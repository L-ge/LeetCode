#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void midOrderTree(TreeNode* root, vector<int>& vecMidOrder)
{
    if(root->left != nullptr)
    {
        midOrderTree(root->left, vecMidOrder);
    }

    vecMidOrder.push_back(root->val);

    if(root->right != nullptr)
    {
        midOrderTree(root->right, vecMidOrder);
    }
}

int kthLargest(TreeNode* root, int k)
{
    vector<int> vecMidOrder;
    midOrderTree(root, vecMidOrder);
    return vecMidOrder[vecMidOrder.size()-k];
}

int main(int argc, char** argv)
{

    return 0;
}
