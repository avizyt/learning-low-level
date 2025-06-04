#include <bits/stdc++.h>
#include <numbers>
using namespace std;

int main()
{
    array<string, 15> colors1 = {"Red", "Green", "Blue", "Cyan",
                                 "Magenta", "Yellow", "Black", "White", "Gray", "Orange", "Brown",
                                 "Pink", "Purple", "Amber", "Teal"};

    // sort(colors1.begin(), colors1.end());
    ranges::sort(colors1);
    for (auto item : colors1)
    {

        cout << item << "\n";
    }
}