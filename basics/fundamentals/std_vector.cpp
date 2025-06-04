#include <bits/stdc++.h>

using namespace std;

template <typename Container>
void printvec(const Container &c)
{
    for (auto it = begin(c); it != end(c); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> numbers;

    generate_n(back_inserter(numbers), 10, [n = 0]() mutable
               { return ++n; });
    printvec(numbers);

    return 0;
}