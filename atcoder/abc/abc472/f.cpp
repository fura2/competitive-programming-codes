#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "geometry/point.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto P = input<vector<Point>>(n);

  vector<Point> Q(n);  // 3 * centroid of triangle
  vector<lint> A(n);   // 2 * area of triangle
  rep (i, n) {
    Q[i] = P[i] + P[(i + 1) % n];
    A[i] = cross(P[i], P[(i + 1) % n]);
  }
  vector<Point> AQcum(2 * n + 1);
  vector<lint> Acum(2 * n + 1);
  AQcum[0] = {0, 0};
  rep (i, 2 * n) {
    AQcum[i + 1] = AQcum[i] + A[i % n] * Q[i % n];
    Acum[i + 1] = Acum[i] + A[i % n];
  }

  rep (_, q) {
    auto i = input<int>() - 1, j = input<int>() - 1;
    if (j < i) j += n;
    Point t = AQcum[j] - AQcum[i];
    lint a = Acum[j] - Acum[i];
    Point s = P[j % n] + P[i];
    lint b = cross(P[j % n], P[i]);
    a += b;
    t += b * s;
    output(t.x / (3.0 * a));
    output(t.y / (3.0 * a));
  }
}
