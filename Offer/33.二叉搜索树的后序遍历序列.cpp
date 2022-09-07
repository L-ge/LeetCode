#include <iostream>
#include <vector>

using namespace std;

bool verifyPostorderImp(vector<int>& postorder, int nBeginIndex, int nEndIndex)
{
    if(nBeginIndex >= nEndIndex)
        return true;

    // �ҵ��ָ������������±�
    int nIndex = nBeginIndex;
    for(; nIndex < nEndIndex; ++nIndex)
    {
        if(postorder[nIndex] > postorder[nEndIndex])
            break;
    }

    // ��ʱ nIndex �����������ĵ�һ�����

    // ������������д��ڱȸ��ڵ�С��ֵ���Ǿ���false
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

    // ʹ�õݹ飺����������ֵ���ȸ��ڵ�С������������ֵ���ȸ��ڵ���Էָ�
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
