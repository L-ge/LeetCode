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
    if(nullptr == head)         // ����0���ֽڵ����
        return nullptr;
    if(nullptr == head->next)   // ����1���ڵ�����
    {
        if(val == head->val)
            return nullptr;
        return head;
    }
    if(val == head->val)        // ����ͷ������Ҫɾ���Ľڵ�����
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
