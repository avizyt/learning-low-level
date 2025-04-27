#include <bits/stdc++.h>
using namespace std;

// Implement using stack, not  optimized
string ReverseVowel(const string &line)
{
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    stack<char> st;

    string newline;
    for (char ch : line)
    {
        if (vowels.count(tolower(ch)))
        {
            st.push(ch);
        }
    }
    for (char ch : line)
    {
        if (vowels.count(tolower(ch)))
        {
            newline.push_back(st.top());
            st.pop();
        }
        else
        {
            newline.push_back(ch);
        }
    }
    return newline;
}

/*
Optimal Code:

Above code use stack, two for loop which is not optimal.

We can use two pointer for optimal use
*/

string ReverseVowelOptimal(string line)
{
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int left = 0, right = line.length() - 1;

    while (left < right)
    {

        // move left pointer until it finds a vowel
        while (left < right && vowels.count(line[left]) == 0)
        {
            left++;
        }
        // move right pointer until it finds a vowel
        while (left < right && vowels.count(line[right]) == 0)
        {
            right--;
        }
        // swap the vowels
        swap(line[left], line[right]);
        left++;
        right--;
    }
    return line;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1 = "DesignGUrus";
    string s2 = "AEIOU";

    string res1 = ReverseVowelOptimal(s1);
    string res2 = ReverseVowelOptimal(s2);

    std::cout << "String 1: " << res1 << std::endl;
    std::cout << "String 2: " << res2 << std::endl;
    return 0;
}