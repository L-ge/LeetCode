#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
    if(0 == pushed.size() && popped.size())
        return true;

    int nIndexPush = 0;
    int nIndexPop = 0;
    std::stack<int> stackData;
    while(nIndexPop < popped.size())
    {
        while(stackData.empty() || stackData.top() != popped[nIndexPop])
        {
            if(nIndexPush >= pushed.size())
                break;
            stackData.push(pushed[nIndexPush]);
            ++nIndexPush;
        }

        // ����Ϊ�������µģ�������Ϊ�ҵ�һ������ȵ�Ԫ�ص��µģ���Ϊ����Ҫ�ж�һ��
        if(stackData.top() != popped[nIndexPop])
            break;

        // ��ȷ���ҵ���һ������ȵ�Ԫ��
        stackData.pop();
        ++nIndexPop;
    }

    // ������֮�����stackData���ǿյĻ���popped���ǿյģ���������
    if(true == stackData.empty() && nIndexPop == pushed.size())
    {
        return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    vector<int> emptyVec;
    cout << validateStackSequences(emptyVec, emptyVec); // true

    vector<int> pushed1{1,2,3,4,5};
    vector<int> popped1{4,5,3,2,1};
    cout << validateStackSequences(pushed1, popped1);

    vector<int> pushed2{0,1};
    vector<int> popped2{0,1};
    cout << validateStackSequences(pushed2, popped2);

    vector<int> pushed3{1,2,3,4,5};
    vector<int> popped3{4,3,5,1,2};
    cout << validateStackSequences(pushed3, popped3);
    return 0;
}
