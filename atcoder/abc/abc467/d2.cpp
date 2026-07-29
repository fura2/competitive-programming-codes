#include "template/template.hpp"

#define MULTI_TESTCASE
#include "geometry/point.hpp"
#include "template/main.hpp"

void testcase() {
  auto p = 2 * input<Point>();
  auto q = 2 * input<Point>();
  auto r = 2 * input<Point>();
  auto s = 2 * input<Point>();

  Point v = q - p, w = s - r;
  if (cross(v, w) != 0) {
    yes();
    return;
  }

  Point a = (p + q) / 2, b = (r + s) / 2;
  Point u = b - a;
  yesno(dot(u, v) == 0);
}
