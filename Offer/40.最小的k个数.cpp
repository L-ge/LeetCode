#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> getLeastNumbers(vector<int>& arr, int k)
{
    if(0 == arr.size() || 0 == k)
        return {};

    // ���� multiset ��ʵ�֣���� multiset ���ˣ���ʱ����ٲ��룬
    // ��������Ԫ�رȽϣ����������Ԫ��С���͵�������Ԫ�أ�ѹ����ȥ
    multiset<int> msetCache;
    for(const auto item : arr)
    {
        if(msetCache.size() < k)
        {
            msetCache.insert(item);
        }
        else
        {
            auto needDelItem = --msetCache.end();
            if(item < *needDelItem)
            {
                msetCache.erase(needDelItem);
                msetCache.insert(item);
            }
        }
    }

    vector<int> vecRet;
    for(const auto item : msetCache)
    {
        vecRet.push_back(item);
    }
    return vecRet;
}

int main(int argc, char** argv)
{
    vector<int> vec = {3,2,1};
    vector<int> vecRet = getLeastNumbers(vec, 2);
    for(const auto item : vecRet)
        cout << item << endl;

    return 0;
}
