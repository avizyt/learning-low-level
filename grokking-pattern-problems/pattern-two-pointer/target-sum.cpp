#include <bits/stdc++.h>
using namespace std;

vector<int> TargetSum(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;

    while (left < right)
    {
        int curr_sum = (arr[left] + arr[right]);

        if (curr_sum == target)
        {
            return {left, right};
        }
        else if (curr_sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {-1, -1};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr = {1, 2, 3, 4, 6};
    int target = 6;
    for (int x : TargetSum(arr, target))
    {
        std::cout << x << std::endl;
    }

    return 0;
}