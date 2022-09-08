#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        // 思想：
        // 1、在每个结点后面加上一个结点，那这样就有两倍长的链表，而且奇数位是原链表，偶数位是复制的链表
        // 2、然后根据原链表结点设置random指针，也就是复制的那个结点根据它前面的那个结点来设置
        // 3、分离出复制的节点，形成结果返回。
        Node* pCurNode = head;
        while(pCurNode != nullptr)
        {
            Node* pCopyNode = new Node(pCurNode->val);
            pCopyNode->next = pCurNode->next;
            pCopyNode->random = nullptr;        // 这里先不设置，第二步再设置

            // 下面两句，相当于第0和第1个结点之间，插入了一个新结点
            pCurNode->next = pCopyNode;
            pCurNode = pCopyNode->next;     // 其实上面复制过了，就是pCurNode->next，也就是第1个节点
        }


        pCurNode = head;
        while(pCurNode != nullptr)
        {
            Node* pCopyNode = pCurNode->next;
            if(pCurNode->random != nullptr)
            {
                pCopyNode->random = pCurNode->random->next;     // 这里是next，因为next才是你copy的那个
            }
            pCurNode = pCopyNode->next;     // 这里不是pCurNode = pCurNode->next;就是为了跳过我们cpoy的那个结点
        }


        pCurNode = head;
        Node* pCopyHead = nullptr;
        Node* pCopyCurNode = nullptr;
        while(pCurNode != nullptr)
        {
            if(nullptr == pCopyHead)    // 先设置一下头结点
            {
                pCopyHead = pCurNode->next;
                pCopyCurNode = pCurNode->next;
                pCurNode->next = pCopyCurNode->next;
                pCurNode = pCurNode->next;
            }
            else
            {
                pCopyCurNode->next = pCurNode->next;
                pCopyCurNode = pCopyCurNode->next;
                pCurNode->next = pCopyCurNode->next;
                pCurNode = pCurNode->next;
            }
        }

        return pCopyHead;
    }
};

int main(int argc, char** argv)
{

    return 0;
}
