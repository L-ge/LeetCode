#include <iostream>
#include <vector>
#include <list>

using namespace std;

int lastRemaining(int n, int m)
{

    /*
    // �������������ʱ...
    // ����70866 116922ʱ�ͳ�ʱ��
    list<int> lstNums;
    for(int i=0; i<n; ++i)
    {
        lstNums.push_back(i);
    }

    list<int>::iterator iterCur = lstNums.begin();
    while(lstNums.size() > 1)
    {
        // �ҵ���m�����
        for(int i=1; i<m; ++i)
        {
            ++iterCur;

            // ��β��֮���ٻص�ͷ
            if(iterCur == lstNums.end())
                iterCur = lstNums.begin();
        }

        // ��ʱ����next
        list<int>::iterator iterNext = ++iterCur;
        if(iterNext == lstNums.end())
            iterNext = lstNums.begin();

        // ����++�ˣ�����--�ص���ǰ���
        --iterCur;
        lstNums.erase(iterCur);
        iterCur = iterNext;
    }

    return *iterCur;*/

    // �����˵���ѧ��
    int nLast = 0;
    for(int i=2; i<=n; ++i)
        nLast = (nLast+m) % i;
    return nLast;
}

int main(int argc, char** argv)
{
    cout << lastRemaining(5, 3) << endl;
    cout << lastRemaining(10, 17) << endl;

    return 0;
}
