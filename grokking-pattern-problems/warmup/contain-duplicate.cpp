#include <bits/stdc++.h>

using namespace std;

int ContainDuplicate(vector<int> arr)
{
    set<int> aset;
    int duplicate = 0;
    if (arr.size() == 0)
    {
        return -1;
    }
    else
    {
        for (int item : arr)
        {
            if (aset.count(item) == 0)
            {
                aset.insert(item);
            }
            else
            {
                duplicate = item;
            }
        }
    }
    return duplicate;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 1};
    std::cout << "Duplicate: " << ContainDuplicate(arr) << std::endl;
}