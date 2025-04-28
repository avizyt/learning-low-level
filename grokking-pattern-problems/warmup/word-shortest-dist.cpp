#include <bits/stdc++.h>
using namespace std;

int ShortestDistance(vector<string> &words, const string &word1, const string &word2)
{
    int index1 = -1, index2 = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < words.size(); ++i)
    {
        if (words[i] == word1)
        {
            index1 = i;
        }
        else if (words[i] == word2)
        {
            index2 = i;
        }

        // only calculate distance if both words have found at least once
        if (index1 != -1 && index2 != -1)
        {
            minDistance = min(minDistance, abs(index1 - index2));
        }
    }
    return minDistance;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // vector<string> words = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    vector<string> words = {"a", "c", "d", "b", "a"};
    // string word1 = "fox";
    string word1 = "a";
    // string word2 = "dog";
    string word2 = "b";

    cout << ShortestDistance(words, word1, word2) << endl;

    return 0;
}