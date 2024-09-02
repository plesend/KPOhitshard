#include <iostream>

int defaultparm(int a, int b, int c, int d, int e = 5, int f = 8, int j = 9)
{
    a += 100;
    return a + b + c;
}

int main()
{
    int k1;
    int k2;

    k2 = defaultparm(1, 2, 3, 4, 5);
    k1 = defaultparm(1, 2, 5, 6, 7, 8, 9);
}