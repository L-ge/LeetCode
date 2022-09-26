#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int add(int a, int b)
{
    int nSum = 0;       // 无进位的相加，用的是异或
    unsigned int nCarry = 0;     // 算出进位
    do
    {
        nSum = a ^ b;
        nCarry = (unsigned int)(a & b) << 1;  // 左移一位，也就是进1
        a = nSum;
        b = nCarry;
    }while(b != 0);      // 也就是直到不产生进位为止
    return a;
}

int main(int argc, char** argv)
{

    return 0;
}
