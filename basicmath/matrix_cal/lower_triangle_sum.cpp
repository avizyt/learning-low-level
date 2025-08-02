
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int i, j, sum = 0;
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      if (i >= j) {
        sum = sum + mat[i][j];
      }
    }
  }
  cout << "Sum of Lower Tringle: " << sum;

  return 0;
}