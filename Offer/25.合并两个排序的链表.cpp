#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(l1 == nullptr && l2 == nullptr)
        return nullptr;
    if(l1 == nullptr && l2 != nullptr)
        return l2;
    if(l1 != nullptr && l2 == nullptr)
        return l1;

    ListNode* pListACur = l1;
    ListNode* pListBCur = l2;
    ListNode* pMergeListHead = nullptr;
    ListNode* pMergeListCur = nullptr;
    while(pListACur != nullptr && pListBCur != nullptr)
    {
        if(pListACur->val > pListBCur->val)
        {
            ListNode* pListBNext = pListBCur->next;
            if(nullptr == pMergeListHead)
            {
                pMergeListHead = pListBCur;
                pMergeListCur = pListBCur;
            }
            else
            {
                pMergeListCur->next = pListBCur;
                pMergeListCur = pMergeListCur->next;
            }

            pListBCur = pListBNext;
        }
        else if (pListACur->val < pListBCur->val)
        {
            ListNode* pListANext = pListACur->next;
            if(nullptr == pMergeListHead)
            {
                pMergeListHead = pListACur;
                pMergeListCur = pListACur;
            }
            else
            {
                pMergeListCur->next = pListACur;
                pMergeListCur = pMergeListCur->next;
            }

            pListACur = pListANext;
        }
        else
        {
            ListNode* pListANext = pListACur->next;
            ListNode* pListBNext = pListBCur->next;
            if(nullptr == pMergeListHead)
            {
                pMergeListHead = pListACur;
                pMergeListCur = pListACur;

                pMergeListCur->next = pListBCur;
                pMergeListCur = pMergeListCur->next;
            }
            else
            {
                pMergeListCur->next = pListACur;
                pMergeListCur = pMergeListCur->next;
                pMergeListCur->next = pListBCur;
                pMergeListCur = pMergeListCur->next;
            }
            pListACur = pListANext;
            pListBCur = pListBNext;
        }
    }

    while(pListACur != nullptr)
    {
        ListNode* pListANext = pListACur->next;
        if(nullptr == pMergeListHead)
        {
            pMergeListHead = pListACur;
            pMergeListCur = pListACur;
        }
        else
        {
            pMergeListCur->next = pListACur;
            pMergeListCur = pMergeListCur->next;
        }
        pListACur = pListANext;
    }

    while(pListBCur != nullptr)
    {
        ListNode* pListBNext = pListBCur->next;
        if(nullptr == pMergeListHead)
        {
            pMergeListHead = pListBCur;
            pMergeListCur = pListBCur;
        }
        else
        {
            pMergeListCur->next = pListBCur;
            pMergeListCur = pMergeListCur->next;
        }
        pListBCur = pListBNext;
    }

    return pMergeListHead;
}

int main(int argc, char** argv)
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = nullptr;

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    l2->next->next->next = nullptr;

    ListNode* ret = mergeTwoLists(l1, l2);
    while(ret != nullptr)
    {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}
