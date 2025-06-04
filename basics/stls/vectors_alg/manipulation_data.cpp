#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> x = {1, 2, 3, 4, 5};
    reverse(x.begin(), x.end());

    for (int m : x)
    {
        cout << m << " ";
    }

    cout << "\n";

    rotate(x.begin(), x.begin() + 1, x.end());
    for (int m : x)
    {
        cout << m << " ";
    }

    int evens = count_if(x.begin(), x.end(), [](int n)
                         { return n % 2 == 0; });

    cout << evens << "\n";

    return 0;
}