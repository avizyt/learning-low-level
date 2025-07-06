
#include <cstddef>
#include <iostream>
#include <istream>
#include <vector>
using namespace std;

/*
Your task is to calculate the area of a given polygon.
The polygon consists of n vertices (x_1,y_1),(x_2,y_2),\dots,(x_n,y_n). The
vertices (x_i,y_i) and (x_{i+1},y_{i+1}) are adjacent for i=1,2,\dots,n-1, and
the vertices (x_1,y_1) and (x_n,y_n) are also adjacent.

Input
The first input line has an integer n: the number of vertices.
After this, there are n lines that describe the vertices. The ith such line has
two integers x_i and y_i. You may assume that the polygon is simple, i.e., it
does not intersect itself.

Output
Print one integer: 2a where the area of the polygon is a (this ensures that the
result is an integer).

Example
Input:
4
1 1
4 2
3 5
1 4

Output:
16

Use Showlace formula
source: https://en.wikipedia.org/wiki/Shoelace_formula

*/

typedef long long ll;

struct Point {
  int x, y;
  Point(int a = 0, int b = 0) : x(a), y(b) {}

  friend istream &operator>>(istream &in, Point &p) {
    int x, y;
    cin >> p.x >> p.y;
    return in;
  }
};
int main() {
  int n;
  cin >> n;
  vector<Point> points(n);
  for (auto &p : points) {
    cin >> p;
  }
  points.push_back(points[0]);

  ll area = 0;
  for (size_t i = 0; i < points.size(); ++i) {
    area += (1LL * points[i].x * points[i + 1].y -
             1LL * points[i].y * points[i + 1].x);
  }
  std::cout << std::abs(area) << std::endl;
}