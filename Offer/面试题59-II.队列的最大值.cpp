#include <iostream>
#include <queue>
#include <deque>

using namespace std;

class MaxQueue {
public:
    MaxQueue()
    {

    }

    int max_value()
    {
        return m_dequeData.empty() ? -1 : m_dequeData.front();
    }

    void push_back(int value)
    {
        m_queueData.push(value);

        // 如果deque中，最后的数比当前要插入的数还要小，那个弹出它，然后把大的数压进队列
        while(false == m_dequeData.empty() && m_dequeData.back() < value)
            m_dequeData.pop_back();
        m_dequeData.push_back(value);
    }

    int pop_front()
    {
        if(true == m_queueData.empty())
            return -1;
        int nVal = m_queueData.front();

        // 如果m_queueData要弹出的值，是记录最大值队列的前面的值，那么记录最大值的队列也要弹出队列首值
        // 肯定是最前面的那个值，不可能是中间或者后面
        if(nVal == m_dequeData.front())
            m_dequeData.pop_front();
        m_queueData.pop();
        return nVal;
    }

private:
    queue<int> m_queueData;
    deque<int> m_dequeData;     // 记录最大值的队列
};

int main(int argc, char** argv)
{
    MaxQueue* obj = new MaxQueue();
    int param_1 = obj->max_value();
    obj->push_back(1);
    obj->push_back(3);
    obj->push_back(2);
    int param_3 = obj->max_value();
    cout << param_3;
    return 0;
}
