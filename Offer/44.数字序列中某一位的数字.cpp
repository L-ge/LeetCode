#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findNthDigit(int n)
{
    // 0 1 2 3 4 ...ƴ���������ַ���
    // string s = "01234567891011121314151617181920";
    int nCurDigit = 1;      // ��ǰλ���������λ����1��ʮλ��2����λ��3...
    while(true)             // ��֪�����������������ֹ��������return
    {
        long long nCurDigitNumberCnt = 0;
        if(1 == nCurDigit)
            nCurDigitNumberCnt = 10;    // ��λ��10������
        else                // ����2λ�����֣���9*10����3λ��������9*100����
            nCurDigitNumberCnt = 9*pow(10, nCurDigit-1);

        long long nCostChar = nCurDigitNumberCnt * nCurDigit;
        if(n < nCostChar)   // ��nCostCharǰ�棬���Ҫ��ǰ���ҵ���λ��
        {
            long long nCurDigitBeginIndex = -1;
            if(1 == nCurDigit)
                nCurDigitBeginIndex = 0;
            else
                nCurDigitBeginIndex = pow(10, nCurDigit-1);

            // ÿ������ռ��nCurDigitλ������17�����������Ӧ����10+(17-10)/2=13
            nCurDigitBeginIndex += (n / nCurDigit);
            long long nPosition = nCurDigit - n % nCurDigit;  // ���ƫ����������17�����������Ӧ����2-(17-10)%2=1
            for(int i=1; i<nPosition; ++i)
                nCurDigitBeginIndex /= 10;      // ��������3��
            return nCurDigitBeginIndex % 10;
        }

        n -= nCostChar;   // �����λռ��10���ַ�����λռ��90*2���ַ�
        ++nCurDigit;
    }
    return -1;
}

int main(int argc, char** argv)
{
    cout << findNthDigit(3) << endl;      // 3
    cout << findNthDigit(11) << endl;     // 0
    cout << findNthDigit(17) << endl;     // 3
    return 0;
}
