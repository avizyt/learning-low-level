#include <bits/stdc++.h>
using namespace std;

// This is my code which is rubish after learning the trick.
// bool IsPangram(string sent)
// {
//     // string sent =  sentence;
//     unordered_map<char, int> m = {
//         {'a', 1},
//         {'b', 1},
//         {'c', 1},
//         {'d', 1},
//         {'e', 1},
//         {'f', 1},
//         {'g', 1},
//         {'h', 1},
//         {'i', 1},
//         {'j', 1},
//         {'k', 1},
//         {'l', 1},
//         {'m', 1},
//         {'n', 1},
//         {'o', 1},
//         {'p', 1},
//         {'q', 1},
//         {'r', 1},
//         {'s', 1},
//         {'t', 1},
//         {'u', 1},
//         {'v', 1},
//         {'w', 1},
//         {'x', 1},
//         {'y', 1},
//         {'z', 1},
//     };
//     for (char ch : sent)
//     {
//         char c = (char)tolower(ch);
//         if (m.at(c) >= 1)
//         {

//             m.at(c) += 1;
//         }
//     }
//     for (char ch : sent)
//     {
//         char c = (char)tolower(ch);
//         if (m.at(c) 2)
//         {
//             return false;
//         }
//     }
//     return true;
// }

bool IsPangramClean(const string &sent)
{
    unordered_set<char> seen;
    for (char ch : sent)
    {
        if (isalpha(ch))
        {
            seen.insert(tolower(ch));
        }
    }
    return seen.size() == 26;
}

string CheckPangram(string sent)
{
    return IsPangramClean(sent) ? "YES" : "NO";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string sentence = "TheQuickBrownFoxJumpsOverTheLazyDog";
    string sent = "This is not a pangram";
    std::cout << IsPangramClean(sentence) << std::endl;
    std::cout << CheckPangram(sent) << std::endl;
    // unordered_map<char, int> m = {
    //     {'a', 1},
    //     {'b', 1},
    // };

    // m.at('a') += 1;
    // for (auto &item : m)
    // {
    //     cout << item.first << item.second << "\n";
    // }

    return 0;
}