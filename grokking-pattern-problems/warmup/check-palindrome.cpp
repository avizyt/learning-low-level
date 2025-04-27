#include <bits/stdc++.h>
using namespace std;
// brute force approaches
string cleanedString(string line)
{
    string s;
    for (char ch : line)
    {
        if (isalnum(ch))
        {
            s.push_back(tolower(ch));
        }
    }
    return s;
}

bool IsPalindrome(string line)
{
    string s = cleanedString(line);
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if (s[left] != s[right])

        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// optimized
bool IsPalindromeOptimize(const string &s)
{
    int left = 0, right = s.length() - 1;

    while (left < right)
    {
        // Move left to next alphanumeric
        while (left < right && !isalnum(s[left]))
        {
            left++;
        }
        // Move right to previous alphanumeric
        while (left < right && !isalnum(s[right]))
        {
            right--;
        }

        // Compare characters
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1 = "A man, a plan, a canal, Panama!";
    std::cout << "s1 is palindrome:" << IsPalindrome(s1) << std::endl;
    // std::cout << "s1 is palindrome:" << IsPalindromeOptimize(s1) << std::endl;
    return 0;
}