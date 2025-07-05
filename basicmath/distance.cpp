#include <cmath>
#include <cstddef>
#include <iostream>

#include <vector>

using namespace std;
typedef vector<pair<double, double>> vp;

struct Point2D {
  double x;
  double y;
};

struct Point3D {
  double x;
  double y;
  double z;
};

double det2D(const Point2D &p1, const Point2D &p2) {
  // The determinant of a 2x2 matrix [[a, b], [c, d]] is (a*d - b*c).
  // If we consider the vectors (p1.x, p1.y) and (p2.x, p2.y) as columns,
  // the matrix is:
  // | p1.x  p2.x |
  // | p1.y  p2.y |
  // Its determinant is (p1.x * p2.y) - (p2.x * p1.y).
  return (p1.x * p2.y) - (p2.x * p1.y);
}

double det3D(const Point3D &p1, const Point3D &p2, const Point3D &p3) {
  // For a 3x3 matrix:
  // | a b c |
  // | d e f |
  // | g h i |
  // Determinant = a(ei - fh) - b(di - fg) + c(dh - eg)

  // Term 1: p1.x * determinant of sub-matrix [[p2.y, p3.y], [p2.z, p3.z]]
  double term1 = p1.x * (p2.y * p3.z - p3.y * p2.z);

  // Term 2: -p1.y * determinant of sub-matrix [[p2.x, p3.x], [p2.z, p3.z]]
  double term2 = p1.y * (p2.x * p3.z - p3.x * p2.z);

  // Term 3: p1.z * determinant of sub-matrix [[p2.x, p3.x], [p2.y, p3.y]]
  double term3 = p1.z * (p2.x * p3.y - p3.x * p2.y);

  // The final determinant is the sum of these terms with alternating signs.
  return term1 - term2 + term3;
}

double calculatePolygonAreaShoelace(const vector<Point2D> &points) {
  double sum = 0.0;
  int n = points.size();
  if (points.size() < 3) {
    cerr
        << "Error: A polygon must have at least 3 points to calculate its area."
        << "\n";
    return 0.0;
  }
  for (size_t i = 0; i < points.size(); ++i) {
    sum += det2D(points[i], points[(i + 1) % n]);
  }
  return sum / 2;
}

double calculatePolygonArea(const std::vector<Point2D> &vertices) {
  // A polygon must have at least 3 vertices to have an area.
  if (vertices.size() < 3) {
    std::cerr << "Error: A polygon must have at least 3 vertices to calculate "
                 "its area."
              << std::endl;
    return 0.0; // Return 0 area for invalid polygons
  }

  double sum1 = 0.0;       // Sum of (x_i * y_{i+1}) terms
  double sum2 = 0.0;       // Sum of (y_i * x_{i+1}) terms
  int n = vertices.size(); // Number of vertices in the polygon

  // Iterate through the vertices to calculate the sums.
  // The loop goes from i = 0 to n-1.
  // For the last vertex (i = n-1), the "next" vertex is the first one (index
  // 0).
  for (int i = 0; i < n; ++i) {
    // Current vertex is vertices[i]
    // Next vertex is vertices[ (i + 1) % n ]
    // The modulo operator '%' handles the wrap-around for the last vertex.
    sum1 += vertices[i].x * vertices[(i + 1) % n].y;
    sum2 += vertices[i].y * vertices[(i + 1) % n].x;
  }

  // The area is half of the absolute difference between the two sums.
  return std::abs(0.5 * (sum1 - sum2));
}

int main() {
  //   vp data;

  //   data = {{1., 2.}, {3., 4.}};
  //   // 1-d
  //   double dist = hypot(data[1].first, data[1].second);

  //   // 2-d
  //   double dist2D =
  //       hypot((data[1].first - data[0].first), (data[1].second -
  //       data[0].second));

  //   cout << "distance 1-D: " << dist << "\n";
  //   cout << "distance 2-D: " << dist2D << "\n";
  //   cout << "Sqrt: " << sqrt(8);

  vector<Point2D> points = {{1., 6.}, {3., 1.}, {7., 2.}, {4., 4.}, {8., 5.}};
  double detSum = det2D(points[0], points[1]) + det2D(points[1], points[2]) +
                  det2D(points[2], points[3]) + det2D(points[3], points[4]) +
                  det2D(points[4], points[5]);

  cout << "Sum of all the point's Determinants: " << detSum << "\n";

  double areaOfPolygon = calculatePolygonAreaShoelace(points);
  cout << "Area enclosed by the polygon from points: " << areaOfPolygon << "\n";
  cout << "Area of Polygon: " << calculatePolygonArea(points);
  return 0;
}