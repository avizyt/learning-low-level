class Point {
  double x;
  double y;
  Point(double _x = 0.0, double _y = 0.0);
  Point operator+(Point &);
  Point operator-(Point &);
  friend Point operator*(double, Point &);
  double operator[](int);
  int operator==(Point &);
  int operator!=(Point &);
  int operator<(Point &);
  int operator>(Point &);
  int classify(Point &, Point &);
  int classify(Edge &);
  double polarAngle(void);
  double length(void);
  double distance(Edge &);
};
// constructor initi new point with x and y coordinates
Point::Point(double _x, double _y) : x(_x), y(_y) {}

Point Point::operator+(Point &p) { return Point(x + p.x, y + p.y); }
Point Point::operator-(Point &p) { return Point(x - p.x, y - p.y); }
Point operator*(double s, Point &p) { return Point(s * p.x, s * p.y); }

double Point::operator[](int i) { return (i == 0) ? x : y; }

int Point::operator==(Point &p) { return (x == p.x) && (y == p.y); }
int Point::operator!=(Point &p) { return !(*this == p); }
int Point::operator<(Point &p) {
  return ((x < p.x) || ((x == p.x) && (y < p.y)));
}
int Point::operator>(Point &p) {
  return ((x > p.x) || ((x == p.x) && (y > p.y)));
}