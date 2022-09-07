#include <iostream>
#include <vector>

using namespace std;

bool verifyPostorderImp(vector<int>& postorder, int nBeginIndex, int nEndIndex)
{
    if(nBeginIndex >= nEndIndex)
        return true;

    // 找到分割左右子树的下标
    int nIndex = nBeginIndex;
    for(; nIndex < nEndIndex; ++nIndex)
    {
        if(postorder[nIndex] > postorder[nEndIndex])
            break;
    }

    // 此时 nIndex 就是右子树的第一个结点

    // 如果在右子树中存在比根节点小的值，那就是false
    for(int i=nIndex; i<nEndIndex; ++i)
    {
        if(postorder[i] < postorder[nEndIndex])
            return false;
    }

    bool bLeftTreeOk = true;
    if(nIndex > nBeginIndex)
    {
        bLeftTreeOk = verifyPostorderImp(postorder, nBeginIndex, nIndex-1);
    }

    bool bRightTreeOk = true;
    if(nIndex < nEndIndex-1)
    {
        bRightTreeOk = verifyPostorderImp(postorder, nIndex, nEndIndex-1);
    }

    return bLeftTreeOk && bRightTreeOk;
}

bool verifyPostorder(vector<int>& postorder)
{
    if(0 == postorder.size())
        return true;

    // 使用递归：左子树结点的值都比根节点小，右子树结点的值都比根节点大，以分割
    return verifyPostorderImp(postorder, 0, postorder.size()-1);
}

int main(int argc, char** argv)
{
    vector<int> vecInput1 = {1,6,3,2,5};
    cout << verifyPostorder(vecInput1) << endl;

    cout << "\n---------------\n";

    vector<int> vecInput2 = {1,3,2,6,5};
    cout << verifyPostorder(vecInput2) << endl;

    return 0;
}
