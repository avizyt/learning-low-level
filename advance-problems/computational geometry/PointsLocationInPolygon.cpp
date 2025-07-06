#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
You are given a polygon of n vertices and a list of m points. Your task is to
determine for each point if it is inside, outside or on the boundary of the
polygon. The polygon consists of n vertices (x_1,y_1),(x_2,y_2),...,(x_n,y_n).
The vertices (x_i,y_i) and (x_{i+1},y_{i+1}) are adjacent for i=1,2,...,n-1,
and the vertices (x_1,y_1) and (x_n,y_n) are also adjacent.

Input
The first input line has two integers n and m: the number of vertices in the
polygon and the number of points. After this, there are n lines that describe
the polygon. The ith such line has two integers x_i and y_i. You may assume that
the polygon is simple, i.e., it does not intersect itself. Finally, there are m
lines that describe the points. Each line has two integers x and y.

Output
For each point, print "INSIDE", "OUTSIDE" or "BOUNDARY".
Constraints

Example
Input:
4 3
1 1
4 2
3 5
1 4
2 3
3 1
1 3

Output:
INSIDE
OUTSIDE
BOUNDARY

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

bool on_segment(const Point &p, const Point &p1, const Point &p2) {
  int a = min(p1.x, p2.x);
  int b = max(p1.x, p2.x);
  int x = min(p1.y, p2.y);
  int y = max(p1.y, p2.y);
  return 1LL * (p.y - p1.y) * (p2.x - p1.x) ==
             1LL * (p.x - p1.x) * (p2.y - p1.y) &&
         a <= p.x && p.x <= b && x <= p.y && p.y <= y;
}
long long trigonometric_sense(Point p, Point p1, Point p2) {
  return 1LL * (p1.x - p.x) * (p2.y - p.y) - 1LL * (p2.x - p.x) * (p1.y - p.y);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<Point> poly(n);
  for (Point &p : poly) {
    cin >> p;
  }
  for (int j = 0; j < m; j++) {
    Point p;
    cin >> p;
    // Intersection count
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;
      if (on_segment(p, poly[i], poly[j])) {
        flag = true;
        break;
      }
      if (poly[i].y <= p.y && p.y < poly[j].y &&
          trigonometric_sense(p, poly[i], poly[j]) > 0)
        cnt++;
      if (poly[j].y <= p.y && p.y < poly[i].y &&
          trigonometric_sense(p, poly[j], poly[i]) > 0)
        cnt++;
    }
    if (flag) {
      cout << "BOUNDARY" << '\n';
    } else {
      cout << (cnt % 2 ? "INSIDE" : "OUTSIDE") << '\n';
    }
  }
}