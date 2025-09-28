#include <iostream>
#include <map>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  map<string, int> ageMap = {{"Lisa", 25}, {"Corbin", 30}, {"Aaron", 22}};

  ageMap["Kristan"] = 28;
  ageMap.insert_or_assign("Lisa", 26);

  if (ageMap.find("Corbin") != ageMap.end()) {
    std::cout << "Corbin exists in the map." << std::endl;
  }

  ageMap["Aaron"] += 1;

  std::cout << "Age recoreds" << std::endl;
  for (const auto &[name, age] : ageMap) {
    std::cout << name << ":" << age << std::endl;
  }

  ageMap.erase("Corbin");

  if (ageMap.count("regan") == 0) {
    std::cout << "Regan does not exist int the map." << std::endl;
  }

  map<string, int, bool (*)(const string &, const string &)> customOrderMap{
      [](const string &lhs, const string &rhs) { return lhs > rhs; }};

  customOrderMap["Lisa"] = 25;
  customOrderMap["Corbin"] = 30;
  customOrderMap["Aaron"] = 22;

  std::cout << "Custo ordered map:" << std::endl;
  for (const auto &[name, age] : customOrderMap) {
    std::cout << name << ":" << age << std::endl;
  }

  return 0;
}