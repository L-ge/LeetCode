#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> findContinuousSequence(int target)
{
    vector<vector<int>> vecResult;
    // �����������У������ʼֵ��1��2...
    int nSmall = 1;
    int nBig = 2;
    // ��Ϊ����������ֵ������Ҫ��9����ônMid=5��4+5=9.���4,5�Ѿ�����̵������ˣ�����ǰ��Ҳ�Ҳ�����
    int nMid = (1 + target) / 2;
    int nCurSum = nSmall + nBig;
    while(nSmall < nMid)
    {
        if(nCurSum == target)
        {
            vector<int> vecTmp;
            for(int i=nSmall; i<=nBig; ++i)
                vecTmp.push_back(i);
            vecResult.push_back(vecTmp);
        }

        // ��ǰ���Ѿ��ܴ��ˣ���ôҪ����ǰ���small����
        while(nCurSum > target && nSmall < nMid)
        {
            nCurSum -= nSmall;
            ++nSmall;

            // ���ж�һ�£���ʱ�����û
            if(nCurSum == target)
            {
                vector<int> vecTmp;
                for(int i=nSmall; i<=nBig; ++i)
                    vecTmp.push_back(i);
                vecResult.push_back(vecTmp);
            }
        }

        // ��ǰ�ͻ���������˼Ӹ�nBig����
        ++nBig;
        nCurSum += nBig;
    }

    return vecResult;
}

int main(int argc, char** argv)
{
    vector<vector<int>> vecResult = findContinuousSequence(9);
    for(auto itemVec : vecResult)
    {
        for(auto itemVec : itemVec)
            cout << itemVec << ",";
        cout << endl;
    }

    return 0;
}
