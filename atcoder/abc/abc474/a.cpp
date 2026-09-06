#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto x = input<int>();
  output(x == 3 ? 1 : x + 1);
}
