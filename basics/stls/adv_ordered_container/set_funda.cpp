#include <bits/stdc++.h>
using namespace std;

int main()
{

    set<int> numbers = {5, 3, 8, 1, 4};

    auto [position, wasInserted] = numbers.insert(6);

    if (wasInserted)
    {
        cout << "6 was inserted into the set. \n";
    }

    auto result = numbers.insert(5);
    if (!result.second)
    {
        cout << "5 is already in the set.\n";
    }

    if (numbers.find(3) != numbers.end())
    {
        cout << "3 is in the set.\n";
    }

    set<int> moreNumbers = {9, 7, 2};
    numbers.merge(moreNumbers);

    std::cout << "After merging: ";
    for (int num : numbers)
    {
        std::cout << " " << num;
    }
    cout << "\n";

    if (numbers.count(2))
    {
        cout << "2 existt in the set.\n";
    }

    set<string, bool (*)(const string &, const string &)>
        caseInsensitiveSet{[](const string &lhs, const string &rhs)
                           {
                               return lexicographical_compare(
                                   lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), [](char a, char b)
                                   { return tolower(a) < tolower(b); });
                           }

        };

    caseInsensitiveSet.insert("Hello");
    if (!caseInsensitiveSet.insert("hello").second)
    {
        std::cout << "Duplicate insertion (case-insensitive) detected." << std::endl;
    }

    return 0;
}