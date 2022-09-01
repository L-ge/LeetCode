#include <iostream>
#include <stack>

using namespace std;

class CQueue
{
public:
    CQueue()
    {

    }

    void appendTail(int value)
    {
        while(stackPop.size() > 0)
        {
            int nTopTmp = stackPop.top();
            stackPop.pop();
            stackPush.push(nTopTmp);
        }
        stackPush.push(value);
    }

    int deleteHead()
    {
        while(stackPush.size() > 0)
        {
            int nTopTmp = stackPush.top();
            stackPush.pop();
            stackPop.push(nTopTmp);
        }

        if(0 == stackPop.size())
            return -1;

        int nResult = stackPop.top();
        stackPop.pop();
        return nResult;
    }
private:
    stack<int> stackPush;
    stack<int> stackPop;
};

int main(int argc, char** argv)
{
    CQueue* obj = new CQueue();
    obj->appendTail(1);
    obj->appendTail(2);
    cout << obj->deleteHead() << endl;
    obj->appendTail(3);
    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;

    return 0;
}
