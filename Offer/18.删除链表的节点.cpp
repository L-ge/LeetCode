#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteNode(ListNode* head, int val)
{
    if(nullptr == head)         // 处理0个字节的情况
        return nullptr;
    if(nullptr == head->next)   // 处理1个节点的情况
    {
        if(val == head->val)
            return nullptr;
        return head;
    }
    if(val == head->val)        // 处理头结点就是要删除的节点的情况
    {
        head = head->next;
        return head;
    }

    ListNode* pLastNode = head;
    ListNode* pCurNode = head->next;

    while(pCurNode)
    {
        if(val == pCurNode->val)
        {
            pLastNode->next = pCurNode->next;
            pCurNode->next = nullptr;
            return head;
        }

        pLastNode = pCurNode;
        pCurNode = pCurNode->next;
    }

    return head;
}

int main(int argc, char** argv)
{
    return 0;
}
