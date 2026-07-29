#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int h = input<int>();
  int w = input<int>();
  yesno(10000 * w >= 25 * h * h);
}
