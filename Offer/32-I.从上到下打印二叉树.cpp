#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> levelOrder(TreeNode* root)
{
    vector<int> vecRet;
    // ��ʵ���ǵ�ǰ�ڵ�����У�Ȼ���������������У�Ȼ��ȡ�������׸����ѹ��vector����ȥ��
    // Ȼ��ȡ����ڵ㣬�����ڵ������������ٽ����У�Ȼ����ڵ�ѹ��vector����ȥ...

    if(nullptr == root)
        return vecRet;
    queue<TreeNode*> qCache;
    qCache.push(root);
    while(qCache.size() > 0)
    {
        TreeNode* pFront = qCache.front();
        qCache.pop();
        vecRet.push_back(pFront->val);
        if(nullptr != pFront->left)
            qCache.push(pFront->left);
        if(nullptr != pFront->right)
            qCache.push(pFront->right);
    }
    return vecRet;
}

int main(int argc, char** argv)
{
    TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);

    vector<int> vecRet = levelOrder(t1);
    for(const auto& item : vecRet)
        cout << item << endl;

    return 0;
}
