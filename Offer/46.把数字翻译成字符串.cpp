#include <iostream>
#include <vector>
#include <string>

using namespace std;

int translateNum(int num)
{
    // �ݹ������϶��½������
    // ���ǵݹ��ڴ���Ŀ���д����ظ��ļ���
    // ���Ҫ�����¶��ϵķ���
    // ����̨���м����������������ƣ���̬�滮����
    string sNum = to_string(num);
    vector<int> vecWay;
    vecWay.resize(sNum.length());
    vecWay[0] = 1;
    for(int i=1; i<sNum.length(); ++i)
    {
        // ��λ����ֻ�����ǵ�һλ��1���ڶ�λ��㣻
        // ���� ��һλ��2���ڶ�λ����6
        if('1' == sNum[i-1] || ('2' == sNum[i-1] && sNum[i] < '6'))
        {
            if(1 == i)
            {
                vecWay[i] = 2;      // 1�Ƚ��ر�
            }
            else
            {
                vecWay[i] = vecWay[i-1] + vecWay[i-2];
            }
        }
        else
        {
            vecWay[i] = vecWay[i-1];
        }
    }

    return vecWay[sNum.length()-1];
}

int main(int argc, char** argv)
{
    cout << translateNum(0) << endl;
    cout << translateNum(12258) << endl;
    return 0;
}
