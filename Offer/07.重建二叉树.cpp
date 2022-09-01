#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeImp(vector<int>& vecPreOrder, vector<int>& vecInOrder,
                       int nPreOrderLeft, int nPreOrderRight,
                       int nInOrderLeft, int nInOrderRight)
{
    if(nPreOrderLeft > nPreOrderRight || nInOrderLeft > nInOrderRight)
        return nullptr;

    // ����������ҵ����ڵ㣬�����Ļ��Ϳ��Էָ�����������
    int nRootIndexInOrder = nInOrderLeft;
    while(nRootIndexInOrder <= nPreOrderRight
          && vecInOrder[nRootIndexInOrder] != vecPreOrder[nPreOrderLeft])
    {
        ++nRootIndexInOrder;
    }

    // ���ݡ�ǰ������ĵ�һ��Ԫ��Ϊ���ڵ㡱�������ڵ�
    TreeNode* pRoot = new TreeNode(vecPreOrder[nPreOrderLeft]);
    // �������Ľڵ����
    int nCntLeft = nRootIndexInOrder - nInOrderLeft;
    // �������Ľڵ����
    int nCntRight = nInOrderRight - nRootIndexInOrder;
    // �ݹ鹹��������
    pRoot->left = buildTreeImp(vecPreOrder, vecInOrder, nPreOrderLeft+1, nPreOrderLeft+nCntLeft, nInOrderLeft, nRootIndexInOrder-1);
    // �ݹ鹹��������
    pRoot->right = buildTreeImp(vecPreOrder, vecInOrder, nPreOrderLeft+nCntLeft+1, nPreOrderRight, nRootIndexInOrder+1, nInOrderRight);

    return pRoot;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    return buildTreeImp(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}

int main(int argc, char** argv)
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    cout << buildTree(preorder, inorder)->val;

    return 0;
}
