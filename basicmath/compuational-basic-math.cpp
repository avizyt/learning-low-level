#include "compgeo.h"
#include <cmath>
#include <iostream>

// --- DOT PRODUCT FUNCTIONS ---

// Calculates the dot product of two 2D vectors (points from origin).
// Formula: A.B = Ax*Bx + Ay*By
// Geometrically: Measures how much two vectors point in the same direction.
double dotProd2D(const Point2D &p1, const Point2D &p2) {
  return (p1.x * p2.x) + (p1.y * p2.y);
}

// Calculates the dot product of two 3D vectors (points from origin).
// Formula: A.B = Ax*Bx + Ay*By + Az*Bz
// Geometrically: Measures how much two vectors point in the same direction.
double dotProduct3D(const Point3D &v1, const Point3D &v2) {
  return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

// --- CROSS PRODUCT FUNCTION ---

// Calculates the cross product of two 3D vectors (points from origin).
// The cross product is only defined for 3D vectors.
// Formula: A x B = (AyBz - AzBy, AzBx - AxBz, AxBy - AyBx)
// Geometrically: Returns a new vector perpendicular to both v1 and v2.
// Its magnitude is the area of the parallelogram formed by v1 and v2.
// Its direction follows the right-hand rule.

Point3D crossProd3D(const Point3D &p1, const Point3D &p2) {
  Point3D result;
  result.x = (p1.y * p2.z) - (p1.z * p2.y);
  result.x = (p1.z * p2.x) - (p1.x * p2.z);
  result.x = (p1.x * p2.y) - (p1.y * p2.x);
  return result;
}

// --- DISTANCE FUNCTIONS ---

// Calculates the Euclidean distance between two 2D points.
// Formula: d = sqrt((x2-x1)^2 + (y2-y1)^2)
double distance2D(const Point2D &p1, const Point2D &p2) {
  double dx = p2.x - p1.x; // Difference in x-coordinates
  double dy = p2.y - p1.y; // Difference in y-coordinates
  return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}

// Calculates the Euclidean distance between two 3D points.
// Formula: d = sqrt((x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2)
double distance3D(const Point3D &p1, const Point3D &p2) {
  double dx = p2.x - p1.x; // Difference in x-coordinates
  double dy = p2.y - p1.y; // Difference in y-coordinates
  double dz = p2.z - p1.z; // Difference in z-coordinates
  return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2) + std::pow(dz, 2));
}

// --- Main function for demonstration ---
int main() {
  std::cout << "--- Vector Operations and Distance Calculation ---"
            << std::endl;

  // --- Dot Product Examples ---
  std::cout << "\n--- Dot Product ---" << std::endl;

  // 2D Dot Product
  Point2D v2_a = {1.0, 0.0};  // Vector along X-axis
  Point2D v2_b = {0.0, 1.0};  // Vector along Y-axis (orthogonal to v2_a)
  Point2D v2_c = {1.0, 1.0};  // Vector at 45 degrees
  Point2D v2_d = {-1.0, 0.0}; // Vector along negative X-axis

  std::cout << "2D Vectors: v2_a(1,0), v2_b(0,1), v2_c(1,1), v2_d(-1,0)"
            << std::endl;
  std::cout << "v2_a . v2_b (orthogonal): " << dotProd2D(v2_a, v2_b)
            << " (Expected: 0)" << std::endl;
  std::cout << "v2_a . v2_c (same direction): " << dotProd2D(v2_a, v2_c)
            << " (Expected: 1)" << std::endl;
  std::cout << "v2_a . v2_d (opposite direction): " << dotProd2D(v2_a, v2_d)
            << " (Expected: -1)" << std::endl;

  // 3D Dot Product
  Point3D v3_a = {1.0, 2.0, 3.0};
  Point3D v3_b = {4.0, -1.0, 0.0}; // Not orthogonal, but let's see
  Point3D v3_c = {1.0, 1.0, -1.0}; // Orthogonal to {1, 0, 1}

  std::cout << "\n3D Vectors: v3_a(1,2,3), v3_b(4,-1,0), v3_c(1,1,-1)"
            << std::endl;
  std::cout << "v3_a . v3_b: " << dotProduct3D(v3_a, v3_b)
            << " (Expected: (1*4) + (2*-1) + (3*0) = 4 - 2 + 0 = 2)"
            << std::endl;
  std::cout << "v3_a . v3_c: " << dotProduct3D(v3_a, v3_c)
            << " (Expected: (1*1) + (2*1) + (3*-1) = 1 + 2 - 3 = 0)"
            << std::endl;

  // --- Cross Product Examples ---
  std::cout << "\n--- Cross Product (3D Only) ---" << std::endl;

  Point3D v3_x = {1.0, 0.0, 0.0}; // Unit vector along X-axis
  Point3D v3_y = {0.0, 1.0, 0.0}; // Unit vector along Y-axis
  // Point3D v3_z = {0.0, 0.0, 1.0}; // Unit vector along Z-axis

  std::cout << "3D Unit Vectors: v3_x(1,0,0), v3_y(0,1,0), v3_z(0,0,1)"
            << std::endl;

  Point3D cross_xy = crossProd3D(v3_x, v3_y);
  std::cout << "v3_x x v3_y: (" << cross_xy.x << ", " << cross_xy.y << ", "
            << cross_xy.z << ") (Expected: (0,0,1) i.e., v3_z)" << std::endl;

  Point3D cross_yx = crossProd3D(v3_y, v3_x);
  std::cout << "v3_y x v3_x: (" << cross_yx.x << ", " << cross_yx.y << ", "
            << cross_yx.z << ") (Expected: (0,0,-1) i.e., -v3_z)"
            << std::endl; // Cross product is anti-commutative

  Point3D cross_parallel = crossProd3D(v3_x, v3_x);
  std::cout << "v3_x x v3_x (parallel vectors): (" << cross_parallel.x << ", "
            << cross_parallel.y << ", " << cross_parallel.z
            << ") (Expected: (0,0,0))"
            << std::endl; // Cross product of parallel vectors is zero vector

  // --- Distance Examples ---
  std::cout << "\n--- Distance Between Points ---" << std::endl;

  // 2D Distance
  Point2D p2_1 = {0.0, 0.0};
  Point2D p2_2 = {3.0, 4.0}; // A classic 3-4-5 triangle
  Point2D p2_3 = {1.0, 1.0};

  std::cout << "2D Points: p2_1(0,0), p2_2(3,4), p2_3(1,1)" << std::endl;
  std::cout << "Distance between p2_1 and p2_2: " << distance2D(p2_1, p2_2)
            << " (Expected: 5.0)" << std::endl;
  std::cout << "Distance between p2_2 and p2_3: " << distance2D(p2_2, p2_3)
            << " (Expected: sqrt((3-1)^2 + (4-1)^2) = sqrt(2^2 + 3^2) = "
               "sqrt(4+9) = sqrt(13) approx 3.605)"
            << std::endl;

  // 3D Distance
  Point3D p3_1 = {0.0, 0.0, 0.0};
  Point3D p3_2 = {1.0, 2.0,
                  2.0}; // sqrt(1^2 + 2^2 + 2^2) = sqrt(1+4+4) = sqrt(9) = 3
  Point3D p3_3 = {5.0, 5.0, 5.0};

  std::cout << "\n3D Points: p3_1(0,0,0), p3_2(1,2,2), p3_3(5,5,5)"
            << std::endl;
  std::cout << "Distance between p3_1 and p3_2: " << distance3D(p3_1, p3_2)
            << " (Expected: 3.0)" << std::endl;
  std::cout << "Distance between p3_2 and p3_3: " << distance3D(p3_2, p3_3)
            << " (Expected: sqrt((5-1)^2 + (5-2)^2 + (5-2)^2) = sqrt(4^2 + 3^2 "
               "+ 3^2) = sqrt(16+9+9) = sqrt(34) approx 5.83)"
            << std::endl;

  return 0; // Indicate successful execution
}