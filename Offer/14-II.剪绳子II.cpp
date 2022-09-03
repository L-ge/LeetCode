#include <iostream>

using namespace std;

int cuttingRope(int n)
{
    // ʹ��̰���������
    if(n == 2)          // 1*1
        return 1;
    if(n == 3)          // 1*2
        return 2;

    // �����ܵؼ�������Ϊ3�����ӡ�����Ϊɶ��3������Ǹ�����ѧ��ʽ�Ƶ�����
    int nCntOfLen3 = n / 3;
    long long nValue = 1;
    int nLeftN = n % 3; // ʣ���ֻ������0��1��2
    if(1 == nLeftN)     // ���ʣ��1����ô��һ��3���ճ�4��ֵ�������Ϊ 2*2 �Ƚϴ�
    {
        while(nCntOfLen3 > 1)
        {
            nValue *= 3;
            nValue %= 1000000007;
            --nCntOfLen3;
        }
        nValue *= 4;
    }
    else if(2 == nLeftN)
    {
        while(nCntOfLen3 > 0)
        {
            nValue *= 3;
            nValue %= 1000000007;
            --nCntOfLen3;
        }
        nValue *= 2;
    }
    else if(0 == nLeftN)
    {
        while(nCntOfLen3 > 0)
        {
            nValue *= 3;
            nValue %= 1000000007;
            --nCntOfLen3;
        }
    }

    return nValue % 1000000007;
}

int main(int argc, char** argv)
{
    cout << cuttingRope(2) << endl;
    cout << cuttingRope(5) << endl;     // 6
    cout << cuttingRope(10) << endl;
    cout << cuttingRope(54) << endl;    // 387420489
    cout << cuttingRope(120) << endl;   // 953271190
    cout << cuttingRope(127) << endl;   // 439254203
    cout << cuttingRope(1000) << endl;

    return 0;
}
