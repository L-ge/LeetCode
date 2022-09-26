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
    // �ݹ�
    if(nullptr == root)
        return nullptr;
    if(root->val > p->val && root->val > q->val)    // ��ǰ����ֵ��������ֵ�����ǿ���������
        return lowestCommonAncestor(root->left, p, q);
    if(root->val < p->val && root->val < q->val)    // ��ǰ����ֵ��������ֵ��С���ǿ���������
        return lowestCommonAncestor(root->right, p, q);

    // �����Ҳ����p��q�ڵ�ǰ�������ߣ���ǰ�����������������
    return root;
}

int main(int argc, char** argv)
{

    return 0;
}
