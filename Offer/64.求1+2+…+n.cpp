#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int sumNums(int n)
{
    // (1+n)*n/2  ==  n+n^2 / 2
    return (int)(pow(n,2) + n) >> 1;
}

int main(int argc, char** argv)
{

    return 0;
}
