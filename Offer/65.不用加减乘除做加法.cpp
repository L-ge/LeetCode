#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int add(int a, int b)
{
    int nSum = 0;       // �޽�λ����ӣ��õ������
    unsigned int nCarry = 0;     // �����λ
    do
    {
        nSum = a ^ b;
        nCarry = (unsigned int)(a & b) << 1;  // ����һλ��Ҳ���ǽ�1
        a = nSum;
        b = nCarry;
    }while(b != 0);      // Ҳ����ֱ����������λΪֹ
    return a;
}

int main(int argc, char** argv)
{

    return 0;
}
