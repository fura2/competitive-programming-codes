#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int a = input<int>();
  int b = input<int>();
  yesno(3 * a > 2 * b);
}
