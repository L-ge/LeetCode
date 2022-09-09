#include <iostream>
#include <vector>

using namespace std;

int countDigitOne(int n)
{
    // �ֱ�ͳ�Ƹ�λ��ʮλ����λ...��1���ֵĴ����������
    int nResult = 0;
    for(long long nBase=1; nBase<=n; nBase *= 10)
    {
        // ��n=4321��nBase=100 ʱ��
        int nBaseCntTotal = (int)(n / nBase);          // �ж��ٸ�base����ʱnBaseCntTotal=43
        int nBaseLeft = (int)(n % nBase);              // ʣ�¶���β������ʱnCurBaseNum=21
        int nBaseCntCur = nBaseCntTotal % 10;   // ��ǰ��λ���ж��ٸ�base����ʱnBaseCntCur=3
        int nBaseCntHigh = nBaseCntTotal / 10;  // ��λ�ж��ٸ�base����ʱnBaseCntTotal=4��������Ϊ���㵱ǰλ(Ҳ�������ĵ�λ)�ж��ٱ�1

        if(nBaseCntCur > 1)
        {
            //              4321
            //              [4] 3 [21]
            // �仯��Χ��   [0-4] 3  [0-99]
            // ��˾��ǣ�   5    *   100
            nResult += (nBaseCntHigh+1)*nBase;
        }
        else if(nBaseCntCur == 1)   // 1�Ѿ��ǹ̶��ڱ�λ�ˣ����Ե���λ��1��ʱ�򣬲�û��ȫ��1
        {
            //                   4121
            //                   [4] 1 [21]
            // �仯��Χ���1��   [0-3] 1  [0-99]
            // �仯��Χ���2��   [4]   1  [0-21]
            // ��˾��ǣ�        4    *   22     + 1 * (22+1)
            nResult += (nBaseCntHigh*nBase + (nBaseLeft + 1));
        }
        else        // Ҳ����Ϊ0��ʱ��
        {
            //              4021
            //              [4] 0 [21]
            // �仯��Χ��   [0-3] 0  [0-99]
            // ��˾��ǣ�   4    *   100
            nResult += nBaseCntHigh*nBase;
        }
    }

    return nResult;
}

int main(int argc, char** argv)
{
    cout << countDigitOne(12) << endl;      // 5
    cout << countDigitOne(13) << endl;      // 6
    return 0;
}
