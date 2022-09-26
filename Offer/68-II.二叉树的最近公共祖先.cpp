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

    // ���pLeft��pRight����Ϊ�գ���p��q�ֱ��ڵ�ǰ������������
    if(nullptr != pLeft && nullptr != pRight)
        return root;
    // p��q���ڵ�ǰ����������
    if(nullptr != pLeft)
        return pLeft;
    // p��q���ڵ�ǰ����������
    if(nullptr != pRight)
        return pRight;
    return nullptr;
}

int main(int argc, char** argv)
{

    return 0;
}
