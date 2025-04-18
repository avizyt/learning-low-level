#include <iostream>

using namespace std;

int main()
{
    int n = 5, sum = 0, i = 1;
    while (i <= n)
    {
        sum += i;
        ++i;
    }

    cout << "Sum is: " << sum << endl;
}
