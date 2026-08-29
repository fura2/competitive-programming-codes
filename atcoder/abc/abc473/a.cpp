#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);
  output(accumulate(a.begin() + n / 2, a.end(), 0));
}
