#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 4;
    int y = 6;

    int avg = (x + y) / 2;
    // std::cout << "normal avg: " << avg << std::endl;

    int x_and_y = (x & y);
    int x_xor_y = (x ^ y);
    int right_shift = x_xor_y >> 1;
    int avg_bit = (x & y) + ((x ^ y) >> 1);

    std::cout << "*************************" << std::endl;
    std::cout << "x_and_y: " << x_and_y << std::endl;
    std::cout << "x_xor_y: " << x_xor_y << std::endl;
    std::cout << "right shift: " << right_shift << std::endl;
    std::cout << "*************************" << std::endl;

    std::cout << "Bitwise avg: " << avg_bit << std::endl;
}