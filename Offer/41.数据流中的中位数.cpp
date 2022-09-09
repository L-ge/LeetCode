#include <iostream>
#include <set>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder()
    {

    }

    void addNum(int num)
    {
        int nTotalSize = m_msetLeft.size() + m_msetRight.size();
        if(0 == nTotalSize % 2)   // ż����
        {
            if(m_msetLeft.size() > 0)
            {
                auto itemCurMaxValInLeft = --m_msetLeft.end();
                if(num < *itemCurMaxValInLeft)      // ֤��Ҫ���������߶�
                {
                    m_msetLeft.insert(num);
                    // �����ֵ����ߵ���ȥ
                    itemCurMaxValInLeft = --m_msetLeft.end();
                    num = *itemCurMaxValInLeft;
                    m_msetLeft.erase(itemCurMaxValInLeft);
                }
            }
            m_msetRight.insert(num);
        }
        else
        {
            if(m_msetRight.size() > 0)
            {
                auto itemCurMinValInRight = m_msetRight.begin();
                if(num > *itemCurMinValInRight)     // ֤��Ҫ������ұ߶�
                {
                    m_msetRight.insert(num);
                    // ����Сֵ���ұߵ���ȥ
                    itemCurMinValInRight = m_msetRight.begin();
                    num = *itemCurMinValInRight;
                    m_msetRight.erase(itemCurMinValInRight);
                }
            }
            m_msetLeft.insert(num);
        }
    }

    double findMedian()
    {
        int nTotalSize = m_msetLeft.size() + m_msetRight.size();
        //cout << "nTotalSize:" << nTotalSize << endl;
        if(0 == nTotalSize)
        {
            return 0;
        }

        if(0 == nTotalSize % 2)
        {
            auto itemCurMaxValInLeft = --m_msetLeft.end();
            auto itemCurMinValInRight = m_msetRight.begin();
            return ((double)*itemCurMaxValInLeft + (double)*itemCurMinValInRight)/2;
        }
        else
        {
            auto itemCurMinValInRight = m_msetRight.begin();
            return  *itemCurMinValInRight;
        }
    }
private:
    // ��������ʵ�֣���Ԫ�طֿ���������
    multiset<int> m_msetLeft;
    multiset<int> m_msetRight;
};

int main(int argc, char** argv)
{
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    //cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    return 0;
}
