#include <iostream>

using namespace std;

static int rat_things_power = 200;

void power_up_rat_thing(int nuclear_isotopes) {
  rat_things_power = rat_things_power + nuclear_isotopes;
  const auto waste_heat = rat_things_power * 20;
  if (waste_heat > 10000) {
    cout << "Warning! Hot doggie!\n";
  }
}

int main() {
  cout << "Rat-thing power: " << rat_things_power << "\n";
  power_up_rat_thing(100);
  cout << "Rat-thing power: " << rat_things_power << "\n";
  power_up_rat_thing(500);
  cout << "Rat-thing power: " << rat_things_power << "\n";
}