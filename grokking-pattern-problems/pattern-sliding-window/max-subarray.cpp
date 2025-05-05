#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarrays(const vector<int> &arr, int k)
{
    int n = arr.size();

    vector<int> res;

    for (int i = 0; i <= n - k; ++i)
    {
        int max = arr[i];
        for (int j = 1; j < k; ++j)
        {
            if (arr[i + j] > max)
            {
                max = arr[i + j];
            }
        }
        res.push_back(max);
    }
    return res;
}

vector<int> maxOfSubarraysHeap(const vector<int> &arr, int k)
{
    int n = arr.size();

    vector<int> res;
    // to store the max value
    priority_queue<pair<int, int>> heap;

    // init heap with the first k elem
    for (int i = 0; i < k; ++i)
    {
        heap.push({arr[i], i});
    }
    // maximum elem in the first window
    res.push_back(heap.top().first);

    for (int i = k; i < arr.size(); ++i)
    {
        heap.push({arr[i], i});

        while (heap.top().second <= i - k)
        {
            heap.pop();
        }
        res.push_back(heap.top().first);
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    // vector<int> res = maxOfSubarraysHeap(arr, k);
    vector<int> res = maxOfSubarrays(arr, k);

    for (int maxVal : res)
    {
        cout << maxVal << " ";
    }
    return 0;
}