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
        // ˼�룺
        // 1����ÿ�����������һ����㣬������������������������������λ��ԭ����ż��λ�Ǹ��Ƶ�����
        // 2��Ȼ�����ԭ����������randomָ�룬Ҳ���Ǹ��Ƶ��Ǹ���������ǰ����Ǹ����������
        // 3����������ƵĽڵ㣬�γɽ�����ء�
        Node* pCurNode = head;
        while(pCurNode != nullptr)
        {
            Node* pCopyNode = new Node(pCurNode->val);
            pCopyNode->next = pCurNode->next;
            pCopyNode->random = nullptr;        // �����Ȳ����ã��ڶ���������

            // �������䣬�൱�ڵ�0�͵�1�����֮�䣬������һ���½��
            pCurNode->next = pCopyNode;
            pCurNode = pCopyNode->next;     // ��ʵ���渴�ƹ��ˣ�����pCurNode->next��Ҳ���ǵ�1���ڵ�
        }


        pCurNode = head;
        while(pCurNode != nullptr)
        {
            Node* pCopyNode = pCurNode->next;
            if(pCurNode->random != nullptr)
            {
                pCopyNode->random = pCurNode->random->next;     // ������next����Ϊnext������copy���Ǹ�
            }
            pCurNode = pCopyNode->next;     // ���ﲻ��pCurNode = pCurNode->next;����Ϊ����������cpoy���Ǹ����
        }


        pCurNode = head;
        Node* pCopyHead = nullptr;
        Node* pCopyCurNode = nullptr;
        while(pCurNode != nullptr)
        {
            if(nullptr == pCopyHead)    // ������һ��ͷ���
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
