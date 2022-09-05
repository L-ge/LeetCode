#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
    if(nullptr == head)
    {
        return head;
    }

    ListNode* pOriHead = head;
    ListNode* pAfterHead = nullptr;
    while(pOriHead != nullptr)
    {
        ListNode* pOriNext = pOriHead->next;
        if(nullptr == pAfterHead)
        {
            pAfterHead = pOriHead;
            pAfterHead->next = nullptr;
        }
        else
        {
            pOriHead->next = pAfterHead;
            pAfterHead = pOriHead;
        }

        pOriHead = pOriNext;
    }
    return pAfterHead;
}

int main(int argc, char** argv)
{

    return 0;
}
