#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vi arr = {10, 2, 3, 4, 5, 6, 7, 8, 9};

    // using iterator
    // for (vi::iterator itr = arr.begin(); itr != arr.end(); itr++)
    // {
    //     std::cout << *itr << std::endl;
    // }
    while (vi::iterator itr = arr.begin() != arr.end())
    {
        cout << *itr++ << " ";
    }
}