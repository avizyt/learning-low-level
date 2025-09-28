
#include <algorithm>
#include <iostream>
#include <vector>
bool compare(std::vector<int> &a, std::vector<int> &b) {
  double a1 = (1.0 * a[0]) / a[1];
  double b1 = (1.0 * b[0]) / b[1];
  return a1 > b1;
}

double fractioalKnapsack(std::vector<int> &val, std::vector<int> &wt,
                         int capacity) {
  int n = val.size();

  // create 2D vector to store value and weight
  // item[i][0] = value, item[i][1] = weight

  std::vector<std::vector<int>> items(n, std::vector<int>(2));

  for (int i = 0; i < n; ++i) {
    items[i][0] = val[i];
    items[i][1] = wt[i];
  }
  // sort items based in value to weight ratio in descending order
  std::sort(items.begin(), items.end(), compare);

  double res = 0.0;
  int currentCapacity = capacity;

  // process items in sorted order
  for (int i = 0; i < n; ++i) {

    // if we can take the entire item
    if (items[i][1] < currentCapacity) {
      res += items[i][0];
      currentCapacity -= items[i][1];
    }

    // otherwise take a fraction of the item
    else {
      res += (1.0 * items[i][0] / items[i][1]) * currentCapacity;

      // knapsack is full
      break;
    }
  }

  return res;
}

int main() {
  std::vector<int> val = {60, 100, 120};
  std::vector<int> wt = {10, 20, 30};

  int capacity = 50;

  std::cout << fractioalKnapsack(val, wt, capacity) << "\n";

  return 0;
}