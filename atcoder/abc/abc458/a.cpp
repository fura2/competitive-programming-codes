#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  auto n = input<int>();
  output(s.substr(n, s.size() - 2 * n));
}
