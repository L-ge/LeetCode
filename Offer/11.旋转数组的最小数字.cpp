#include <iostream>
#include <vector>

using namespace std;

int minArray(vector<int>& numbers)
{
    // ��ת�����ǰ�沿��������ģ����沿��Ҳ������ģ���ô��Сֵ�������м�ָ���λ��
    // ��ˣ�ʹ�ö��ֲ��ҷ�

    int nIndexBegin = 0;
    int nIndexEnd = numbers.size() - 1;
    int nIndexMid = nIndexBegin;
    // numbers[nIndexBegin] >= numbers[nIndexEnd] ��Ϊ�˴��� {1,2} �������
    while(nIndexBegin < nIndexEnd && numbers[nIndexBegin] >= numbers[nIndexEnd])
    {
        // �ٽ�ֵ���ص���ǣ�ǰ��ֵһ�����ڻ���ں����ֵ����������λ�������ڵ�
        if(1 == (nIndexEnd - nIndexBegin))
        {
            nIndexMid = nIndexEnd;
            break;
        }

        // �����±꣬��С��Χ
        nIndexMid = (nIndexBegin + nIndexEnd) / 2;

        // ��������±궼��ȣ���˳�����
        if(numbers[nIndexBegin] == numbers[nIndexMid]
           && numbers[nIndexEnd] == numbers[nIndexMid])
        {
            int nMin = numbers[nIndexBegin];
            for(int i=nIndexBegin+1; i<=nIndexEnd; ++i)
            {
                if(nMin > numbers[i])
                    nMin = numbers[i];
            }
            return nMin;
        }

        if(numbers[nIndexMid] >= numbers[nIndexBegin])
        {
            nIndexBegin = nIndexMid;
        }
        else if(numbers[nIndexMid] <= numbers[nIndexEnd])
        {
            nIndexEnd = nIndexMid;
        }
    }

    return numbers[nIndexMid];
}

int main(int argc, char** argv)
{
    vector<int> numbers1{3, 4, 5, 1, 2};
    vector<int> numbers2{2, 2, 2, 0, 1};
    vector<int> numbers3{1};
    vector<int> numbers4{1,2};
    vector<int> numbers5{10, 1, 10, 10, 10};


    cout << minArray(numbers1) << endl;
    cout << minArray(numbers2) << endl;
    cout << minArray(numbers3) << endl;
    cout << minArray(numbers4) << endl;
    cout << minArray(numbers5) << endl;

    return 0;
}
