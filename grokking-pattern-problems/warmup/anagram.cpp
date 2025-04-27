#include <bits/stdc++.h>
using namespace std;

bool IsAnagram(const string &word1, const string &word2)
{
    if (word1.length() != word2.length())
    {
        return false;
    }

    vector<int> count(26, 0); // 26 letters

    for (int i = 0; i < word1.length(); ++i)
    {
        count[word1[i] - 'a']++;
        count[word2[i] - 'a']--;
    }

    for (int val : count)
    {
        if (val != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s = "anagram";
    string t = "nagaram";

    cout << boolalpha << IsAnagram(s, t) << endl;

    string x = "rat";
    string y = "car";

    cout << boolalpha << IsAnagram(x, y) << endl;

    return 0;
}