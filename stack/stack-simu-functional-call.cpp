#include <iostream>

void bar(int x)
{
    int z = x + 10;
    std::cout << "[bar] address of x: " << &x << std::endl;
    std::cout << "[bar] address of z: " << &z << std::endl;
}

void foo()
{
    int y = 20;
    std::cout << "[foo] address of y: " << &y << std::endl;
    bar(y);
}

int main()
{
    int a = 10;
    std::cout << "[main] address of a: " << &a << std::endl;
    foo();
    return 0;
}