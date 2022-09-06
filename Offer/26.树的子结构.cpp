#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSubTreeOk(TreeNode* A, TreeNode* B)
{
    if(B == nullptr)    // 子树已经到底了，证明匹配成功了
        return true;

    if(A == nullptr)    // 子树还没到底，A却到底了，证明匹配失败
        return false;

    if(A->val != B->val)
        return false;

    // 递归左右子树
    return isSubTreeOk(A->left, B->left) && isSubTreeOk(A->right, B->right);
}

bool isSubStructure(TreeNode* A, TreeNode* B)
{
    // 递归实现
    bool bHasSubTree = false;
    if(A != nullptr && B != nullptr)
    {
        if(A->val == B->val)
        {
            bHasSubTree = isSubTreeOk(A, B);    // 继续遍历其子树
        }
        if(false == bHasSubTree)
        {
            bHasSubTree = isSubStructure(A->left, B);
        }
        if(false == bHasSubTree)
        {
            bHasSubTree = isSubStructure(A->right, B);
        }
    }
    return bHasSubTree;
}

int main(int argc, char** argv)
{
    /*TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(4);
    t1->right = new TreeNode(5);
    t1->left->left = new TreeNode(1);
    t1->left->right = new TreeNode(2);

    TreeNode* t2 = new TreeNode(4);
    t2->left = new TreeNode(1);
    cout << isSubStructure(t1, t2) << endl;*/


    TreeNode* t1 = new TreeNode(4);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    t1->left->right = new TreeNode(5);
    t1->right->left = new TreeNode(6);
    t1->right->right = new TreeNode(7);
    t1->left->left->left = new TreeNode(8);
    t1->left->left->right = new TreeNode(9);

    TreeNode* t2 = new TreeNode(4);
    t2->left = new TreeNode(8);
    t2->right = new TreeNode(9);

    cout << isSubStructure(t1, t2) << endl;

    return 0;
}
