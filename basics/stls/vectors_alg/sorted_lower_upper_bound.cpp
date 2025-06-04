#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> numbers = {1, 3, 3, 5, 7};

    int findVal = 3;
    auto low1 = lower_bound(numbers.begin(), numbers.end(), findVal);
    std::cout << "Lower bound 3: " << (low1 - numbers.begin()) << std::endl;

    auto upp1 = upper_bound(numbers.begin(), numbers.end(), 4);
    std::cout << "Upper bound 4: " << (upp1 - numbers.begin()) << std::endl;
}