#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto a = input<int>();
  output(400 % a == 0 ? 400 / a : -1);
}
