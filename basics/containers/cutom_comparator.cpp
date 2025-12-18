#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Person {
  std::string name;
  int age;
  double salary;
};

void customComparison() {
  std::vector<Person> people = {
      {"Alice", 30, 50000}, {"Bob", 25, 60000}, {"Charlie", 35, 45000}};

  // sort by age using lambda
  std::sort(people.begin(), people.end(),
            [](const Person &a, const Person &b) { return a.age < b.age; });

  // sort by multiple criteria
  std::sort(people.begin(), people.end(), [](const Person &a, const Person &b) {
    if (a.salary != b.salary)
      return a.salary > b.salary;
    return a.name < b.name;
  });

  // custom perdicate for finding
  auto middle_aged =
      std::find_if(people.begin(), people.end(),
                   [](const Person &p) { return p.age >= 30 && p.age <= 50; });

  // remove if with predicate
  people.erase(std::remove_if(people.begin(), people.end(),
                              [](const Person &p) { return p.salary < 50000; }),
               people.end());
}

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}