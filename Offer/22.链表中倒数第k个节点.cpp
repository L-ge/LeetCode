#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getKthFromEnd(ListNode* head, int k)
{
    if(nullptr == head)
    {
        return head;
    }

    // 只遍历一次，用两个指针，两个指针差距是k个结点，但后面的结点到尾巴时，前面的结点就是倒数第k个结点
    ListNode* pNodeBefore = head;
    ListNode* pNodeAfter = head;

    // 先让pNodeBefore和pNodeAfter差k个结点
    // 要考虑不够k个结点的情况
    for(int i=0; i<k-1; ++i)
    {
        ListNode* pNextTmp = pNodeAfter->next;
        if(nullptr == pNextTmp)
        {
            return nullptr;
        }
        pNodeAfter = pNextTmp;
    }

    while(pNodeAfter->next != nullptr)
    {
        pNodeAfter = pNodeAfter->next;
        pNodeBefore = pNodeBefore->next;
    }

    return pNodeBefore;
}

int main(int argc, char** argv)
{

    return 0;
}
