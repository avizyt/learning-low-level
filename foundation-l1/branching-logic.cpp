#include <iostream>

using namespace std;

int main()
{
    int score = 89;

    if (score >= 90)
    {
        cout << "Grade: A\n";
    }
    else if (score >= 75)
    {
        cout << "Grade: B\n";
    }
    else
    {
        cout << "Grade: C or below\n";
    }

    return 0;
}