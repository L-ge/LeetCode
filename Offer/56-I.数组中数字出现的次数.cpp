#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumbers(vector<int>& nums)
{
    // �������ͬ0��1���ص�
    // �������������ֶ����������Σ���ͬ������������0��

    int nAllNumXOR = 0;
    for(const auto item : nums)
        nAllNumXOR ^= item;

    // ��������Ľ���У������Ʊ�ʾ�У��ҵ�һ��1
    unsigned int nIndexBit1 = 0;
    while((nAllNumXOR & 1) == 0 && (nIndexBit1 < 8*sizeof(int)))
    {
        nAllNumXOR = nAllNumXOR >> 1;
        ++nIndexBit1;
    }

    // ����һ��ѭ��֮��nNeedFindNum1 ���ǵ� nIndexBit1 λ��1 ���Ǹ�����
    // ������꣬�� nIndexBit1 λ����1 ���Ǹ�����������Ҫ�ҵ��Ǹ�����
    int nNeedFindNum1 = 0;
    int nNeedFindNum2 = 0;
    for(const auto item : nums)
    {
        // �ҵ�һ���������Ķ����Ʊ�ʾ�У��� nIndexBit1 λ��1
        int nTmp = item >> nIndexBit1;
        if(nTmp & 1)
        {
            nNeedFindNum1 ^= item;
        }
        else
        {
            nNeedFindNum2 ^= item;
        }
    }
    return {nNeedFindNum1, nNeedFindNum2};
}

int main(int argc, char** argv)
{

    return 0;
}
