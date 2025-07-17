#include <iostream>
int add2(int i, int j)
{
    int k = j + i + 2;
    return k;
}
int mul(int a, int b)
{
    int c = a * b + 10;
    return c;
}
int main()
{
    std::cout << add2(3, 5) << std::endl;
    std::cout << mul(10, 20) << std::endl;
}