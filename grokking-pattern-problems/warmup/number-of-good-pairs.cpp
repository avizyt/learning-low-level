#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int NumberOfGoodPair(vi &nums)
{
    unordered_map<int, int> m;
    int numberOfPair = 0;
    for (int num : nums)
    {
        numberOfPair += m[num];
        m[num]++;
    }
    return numberOfPair;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vi nums = {1, 2, 3, 1, 1, 3};
    std::cout << "Number of pairs: " << NumberOfGoodPair(nums) << std::endl;

    return 0;
}