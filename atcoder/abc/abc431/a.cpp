#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto a = input<int>(), b = input<int>();
  output(max(a - b, 0));
}
