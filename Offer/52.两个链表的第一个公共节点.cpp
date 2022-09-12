#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // ˼�룺���õ���������ĳ��ȣ�Ȼ��õ���ֵx��Ȼ�󳤵���������x����Ȼ����һ���ߣ�ֱ��������ͬ�Ľ��
    ListNode *pNodeA = headA;
    int nLengthA = 0;
    while(pNodeA != nullptr)
    {
        ++nLengthA;
        pNodeA = pNodeA->next;
    }

    ListNode *pNodeB = headB;
    int nLengthB = 0;
    while(pNodeB != nullptr)
    {
        ++nLengthB;
        pNodeB = pNodeB->next;
    }

    int nDiff = 0;
    ListNode *pNodeLong = nullptr;
    ListNode *pNodeShort = nullptr;
    if(nLengthA > nLengthB)
    {
        nDiff = nLengthA - nLengthB;
        pNodeLong = headA;
        pNodeShort = headB;
    }
    else
    {
        nDiff = nLengthB - nLengthA;
        pNodeLong = headB;
        pNodeShort = headA;
    }

    while(nDiff > 0)
    {
        pNodeLong = pNodeLong->next;
        --nDiff;
    }

    while(pNodeLong != nullptr && pNodeShort != nullptr && pNodeLong != pNodeShort)
    {
        pNodeLong = pNodeLong->next;
        pNodeShort = pNodeShort->next;
    }

    return pNodeLong;
}

int main(int argc, char** argv)
{

    return 0;
}
