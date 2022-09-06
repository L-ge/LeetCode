#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {

    }

    void push(int x)
    {
        m_stackData.push(x);
        if(0 == m_stackMin.size() || x < m_stackMin.top())
            m_stackMin.push(x);
        else
            m_stackMin.push(m_stackMin.top());
    }

    void pop()
    {
        if(m_stackData.size() > 0 && m_stackMin.size() > 0)
        {
            m_stackData.pop();
            m_stackMin.pop();
        }
    }

    int top()
    {
        if(m_stackData.size() > 0)
            return m_stackData.top();
        else
            return -1;
    }

    int min()
    {
        if(m_stackData.size() > 0)
            return m_stackMin.top();
        else
            return -1;
    }

private:
    stack<int> m_stackData;
    stack<int> m_stackMin;
};

int main(int argc, char** argv)
{
    MinStack* obj = new MinStack();
    obj->push(2);
    obj->push(1);
    obj->push(3);
    obj->push(4);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->min();

    cout << param_3 << endl;
    cout << param_4 << endl;

    return 0;
}
