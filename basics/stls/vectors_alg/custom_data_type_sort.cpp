#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{ // member variables
    string name;
    int age{0};

    // constructor
    Person(string n, int a) : name(n), age(a) {}

    // friend overload output operator
    friend ostream &operator<<(ostream &os, const Person &p)
    {
        os << p.name << " (" << p.age << ")";
        return os;
    }
};

int main()
{
    vector<Person> people = {
        Person("Regan", 30),
        Person("Lisa", 40),
        Person("Corbin", 45)};

    auto compareByName = [](const Person &a, const Person &b)
    {
        return a.name < b.name;
    };

    cout
        << "\n Sorted by name: \n";
    sort(people.begin(), people.end(), compareByName);
    for (const auto &p : people)
    {
        cout << p << "\n";
    }

    auto compareByAge = [](
                            const Person &a, const Person &b)
    {
        return a.age < b.age;
    };

    sort(people.begin(), people.end(), compareByAge);

    cout
        << "\n Sorted by age: \n";
    for (const auto &p : people)
    {
        cout << p << "\n";
    }
    return 0;
}
