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

    // ֻ����һ�Σ�������ָ�룬����ָ������k����㣬������Ľ�㵽β��ʱ��ǰ��Ľ����ǵ�����k�����
    ListNode* pNodeBefore = head;
    ListNode* pNodeAfter = head;

    // ����pNodeBefore��pNodeAfter��k�����
    // Ҫ���ǲ���k���������
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
