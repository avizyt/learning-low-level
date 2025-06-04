#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int grade;

    Student(string n, int g) : name(n), grade(g) {}

    friend ostream &operator<<(ostream &os, Student &s)
    {
        os << s.name << " (" << s.grade << ")";
        return os;
    }
};

// Lambda is good but a struct will be better
struct SortByGradeThenName
{
    bool operator()(const Student &a, Student &b) const
    {
        if (a.grade == b.grade)
        {
            return (a.name < b.name);
        }
        return (a.grade > b.grade);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<Student>
        students = {
            Student("a1", 35),
            Student("b1", 50),
            Student("c1", 15),
            Student("d1", 25),
            Student("e1", 45),
        };

    // sort using lambda pred

    // sort(students.begin(), students.end(), [](const Student &a, Student &b)
    //      {
    //     if(a.grade == b.grade){ return (a.name < b.name);}
    //     return (a.grade > b.grade); });

    // predicate using struct
    sort(students.begin(), students.end(), SortByGradeThenName());
    for (auto student : students)
    {
        cout << student << "\n";
    }

    return 0;
}
