#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


vector<int> reversePrint(ListNode* head)
{
    // 利用栈-先进后出的特点
    std::stack<ListNode*> lstNodes;
    ListNode* pNode = head;
    while(pNode != nullptr)
    {
        lstNodes.push(pNode);
        pNode = pNode->next;
    }

    vector<int> vecResult;
    while(false == lstNodes.empty())
    {
        ListNode* pNodeTmp = lstNodes.top();
        vecResult.push_back(pNodeTmp->val);
        lstNodes.pop();
    }
    return vecResult;
}

int main(int argc, char** argv)
{
    ListNode node1(1);
    ListNode node2(3);
    ListNode node3(2);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = nullptr;

    vector<int> vecRet = reversePrint(&node1);
    for(const auto& item : vecRet)
    {
        cout << item << ", ";
    }

    return 0;
}
