#include <iostream>
#include <vector>

using namespace std;

int cuttingRope(int n)
{
    // ʹ�ö�̬�滮�������
    if(n == 2)          // 1*1
        return 1;
    if(n == 3)          // 1*2
        return 2;

    vector<int> vecWay;
    vecWay.resize(n+1);

    // ��ʼ�����漸������ģ���Ϊ��������ʱ�����������е���Щֵ��
    // ���ֽ��ʱ������Ǹ����ֵ������3������ʱ��1*2���ֽ�ʱ��3
    vecWay[0] = 0;
    vecWay[1] = 1;
    vecWay[2] = 2;
    vecWay[3] = 3;

    for(int i=4; i<=n; ++i)
    {
        int nMaxValue = 0;
        // j�Ǵ�1��ʼ����Ϊ0���ǲ����ˣ�����i���Լ��������ٷֽ�
        for(int j=1; j<=i/2; ++j)   // һֱ�㵽i/2���У���Ϊ���涼���ظ���
        {
            int nValueTmp = vecWay[j] * vecWay[i-j];
            if(nValueTmp > nMaxValue)
                nMaxValue = nValueTmp;
            vecWay[i] = nMaxValue;
        }
    }

    return vecWay[n];
}

int main(int argc, char** argv)
{
    cout << cuttingRope(2) << endl;
    cout << cuttingRope(10) << endl;

    return 0;
}
