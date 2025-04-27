#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s = "A man, a plan, a canal, Panama!";
    std::cout << "Old string: " << s << std::endl;
    string line;
    for (char ch : s)
    {
        if (isalpha(ch))
        {
            line.push_back(tolower(ch));
        }
    }
    std::cout << "New string: " << line << std::endl;
    return 0;
}