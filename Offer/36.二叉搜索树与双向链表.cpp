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
        midOrderTree(pCurNode->left, pLastNodeInList);      // 递归左子树
    }

    // 递归完左子树之后，返回的 *pLastNodeInList 正是 pCurNode 的左节点，中序遍历就是这样的
    pCurNode->left = *pLastNodeInList;      // 要加个*才行，因为传入的&pLastNodeInList
    if(nullptr != (*pLastNodeInList))
    {
        (*pLastNodeInList)->right = pCurNode;   // 循环链表
    }

    *pLastNodeInList = pCurNode;        // 更新当前链表的最后一个结点

    if(nullptr != pCurNode->right)
    {
        midOrderTree(pCurNode->right, pLastNodeInList);      // 递归右子树
    }

    // 递归完右子树之后，还要处理一下最后的结点要指向头结点。这个在外面处理，因为它不是递归的一部分
}

Node* treeToDoublyList(Node* root)
{
    if(nullptr == root)
    {
        return nullptr;
    }

    Node* pLastNodeInList = nullptr;        // 指向双向链表的尾结点
    // 中序遍历
    midOrderTree(root, &pLastNodeInList);

    // 找到头结点
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
