#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void pathSumImp(TreeNode* root, int target, std::vector<int>& vecPath, int nCurSum, vector<vector<int>>& vecResult)
{
    nCurSum += root->val;
    vecPath.push_back(root->val);

    // 如果当前节点是叶子节点且路径和与target相等，则把路径存起来
    if(nullptr == root->left && nullptr == root->right && nCurSum == target)
    {
        vecResult.push_back(vecPath);
    }

    // 递归左右子树
    if(nullptr != root->left)
    {
        pathSumImp(root->left, target, vecPath, nCurSum, vecResult);
    }
    if(nullptr != root->right)
    {
        pathSumImp(root->right, target, vecPath, nCurSum, vecResult);
    }

    // 递归完，回退当前节点
    vecPath.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int target)
{
    if(nullptr == root)
        return {};
    vector<vector<int>> vecResult;
    std::vector<int> vecPath;
    pathSumImp(root, target, vecPath, 0, vecResult);
    return vecResult;
}

int main(int argc, char** argv)
{
    TreeNode* t1 = new TreeNode(5);
    t1->left = new TreeNode(4);
    t1->right = new TreeNode(8);
    t1->left->left = new TreeNode(11);
    t1->right->left = new TreeNode(13);
    t1->right->right = new TreeNode(4);
    t1->left->left->left = new TreeNode(7);
    t1->left->left->right = new TreeNode(2);
    t1->right->right->left = new TreeNode(5);
    t1->right->right->right = new TreeNode(1);

    vector<vector<int>> vecRet = pathSum(t1, 22);
    for(const auto& item : vecRet)
    {
        for(const auto& itemTmp : item)
        {
            cout << itemTmp << "\t";
        }
        cout << endl;
    }

    return 0;
}
