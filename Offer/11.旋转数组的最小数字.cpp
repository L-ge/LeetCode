#include <iostream>
#include <vector>

using namespace std;

int minArray(vector<int>& numbers)
{
    // 旋转数组的前面部分是有序的，后面部分也是有序的，那么最小值就是在中间分隔的位置
    // 因此，使用二分查找法

    int nIndexBegin = 0;
    int nIndexEnd = numbers.size() - 1;
    int nIndexMid = nIndexBegin;
    // numbers[nIndexBegin] >= numbers[nIndexEnd] 是为了处理 {1,2} 这种情况
    while(nIndexBegin < nIndexEnd && numbers[nIndexBegin] >= numbers[nIndexEnd])
    {
        // 临界值的特点就是：前面值一定大于或等于后面的值，且两个的位置是相邻的
        if(1 == (nIndexEnd - nIndexBegin))
        {
            nIndexMid = nIndexEnd;
            break;
        }

        // 更新下标，缩小范围
        nIndexMid = (nIndexBegin + nIndexEnd) / 2;

        // 如果三个下标都相等，则顺序查找
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
