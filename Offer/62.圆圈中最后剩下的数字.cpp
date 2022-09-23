#include <iostream>
#include <vector>
#include <list>

using namespace std;

int lastRemaining(int n, int m)
{

    /*
    // 下面这个方法超时...
    // 输入70866 116922时就超时了
    list<int> lstNums;
    for(int i=0; i<n; ++i)
    {
        lstNums.push_back(i);
    }

    list<int>::iterator iterCur = lstNums.begin();
    while(lstNums.size() > 1)
    {
        // 找到第m个结点
        for(int i=1; i<m; ++i)
        {
            ++iterCur;

            // 到尾巴之后，再回到头
            if(iterCur == lstNums.end())
                iterCur = lstNums.begin();
        }

        // 临时缓存next
        list<int>::iterator iterNext = ++iterCur;
        if(iterNext == lstNums.end())
            iterNext = lstNums.begin();

        // 上面++了，现在--回到当前结点
        --iterCur;
        lstNums.erase(iterCur);
        iterCur = iterNext;
    }

    return *iterCur;*/

    // 看别人的数学法
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
