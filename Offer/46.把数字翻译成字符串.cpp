#include <iostream>
#include <vector>
#include <string>

using namespace std;

int translateNum(int num)
{
    // 递归是自上而下解决问题
    // 但是递归在此题目中有大量重复的计算
    // 因此要用自下而上的方法
    // 和跳台阶有几种跳法的问题类似，动态规划问题
    string sNum = to_string(num);
    vector<int> vecWay;
    vecWay.resize(sNum.length());
    vecWay[0] = 1;
    for(int i=1; i<sNum.length(); ++i)
    {
        // 两位数，只可能是第一位是1，第二位随便；
        // 或者 第一位是2，第二位少于6
        if('1' == sNum[i-1] || ('2' == sNum[i-1] && sNum[i] < '6'))
        {
            if(1 == i)
            {
                vecWay[i] = 2;      // 1比较特别
            }
            else
            {
                vecWay[i] = vecWay[i-1] + vecWay[i-2];
            }
        }
        else
        {
            vecWay[i] = vecWay[i-1];
        }
    }

    return vecWay[sNum.length()-1];
}

int main(int argc, char** argv)
{
    cout << translateNum(0) << endl;
    cout << translateNum(12258) << endl;
    return 0;
}
