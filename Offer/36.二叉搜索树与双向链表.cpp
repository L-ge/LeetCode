#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

void midOrderTree(Node* root, Node** pLastNodeInList)
{
    if(nullptr == root)
        return;
    Node* pCurNode = root;
    if(nullptr != pCurNode->left)
    {
        midOrderTree(pCurNode->left, pLastNodeInList);      // �ݹ�������
    }

    // �ݹ���������֮�󣬷��ص� *pLastNodeInList ���� pCurNode ����ڵ㣬�����������������
    pCurNode->left = *pLastNodeInList;      // Ҫ�Ӹ�*���У���Ϊ�����&pLastNodeInList
    if(nullptr != (*pLastNodeInList))
    {
        (*pLastNodeInList)->right = pCurNode;   // ѭ������
    }

    *pLastNodeInList = pCurNode;        // ���µ�ǰ��������һ�����

    if(nullptr != pCurNode->right)
    {
        midOrderTree(pCurNode->right, pLastNodeInList);      // �ݹ�������
    }

    // �ݹ���������֮�󣬻�Ҫ����һ�����Ľ��Ҫָ��ͷ��㡣��������洦����Ϊ�����ǵݹ��һ����
}

Node* treeToDoublyList(Node* root)
{
    if(nullptr == root)
    {
        return nullptr;
    }

    Node* pLastNodeInList = nullptr;        // ָ��˫�������β���
    // �������
    midOrderTree(root, &pLastNodeInList);

    // �ҵ�ͷ���
    Node* pHead = pLastNodeInList;
    while(pHead != nullptr && pHead->left != nullptr)
        pHead = pHead->left;

    pLastNodeInList->right = pHead;
    pHead->left = pLastNodeInList;
    return pHead;
}

int main(int argc, char** argv)
{

    return 0;
}
