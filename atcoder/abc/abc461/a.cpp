#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int a = input<int>();
  int d = input<int>();
  yesno(a <= d);
}
