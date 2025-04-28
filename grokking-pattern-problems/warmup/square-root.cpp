#include <bits/stdc++.h>
using namespace std;
int SquareRoot(int N)
{
    // MSB of N is ln(N)
    int msb = (int)(log2(N));

    int a = 1 << msb;
    int result = 0;
    while (a != 0)
    {
        if ((result + a) * (result + a) <= N)
        {
            result += a;
        }
        a >>= 1;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N = 8;
    std::cout << "Sqr root: " << SquareRoot(N) << std::endl;

    return 0;
}