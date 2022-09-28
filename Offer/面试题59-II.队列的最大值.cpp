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

        // ���deque�У��������ȵ�ǰҪ���������ҪС���Ǹ���������Ȼ��Ѵ����ѹ������
        while(false == m_dequeData.empty() && m_dequeData.back() < value)
            m_dequeData.pop_back();
        m_dequeData.push_back(value);
    }

    int pop_front()
    {
        if(true == m_queueData.empty())
            return -1;
        int nVal = m_queueData.front();

        // ���m_queueDataҪ������ֵ���Ǽ�¼���ֵ���е�ǰ���ֵ����ô��¼���ֵ�Ķ���ҲҪ����������ֵ
        // �϶�����ǰ����Ǹ�ֵ�����������м���ߺ���
        if(nVal == m_dequeData.front())
            m_dequeData.pop_front();
        m_queueData.pop();
        return nVal;
    }

private:
    queue<int> m_queueData;
    deque<int> m_dequeData;     // ��¼���ֵ�Ķ���
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
