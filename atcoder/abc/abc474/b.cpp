#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto p = input<vector<int>>(n, 1);
  rep (i, n) {
    if (p[i] / 10 != i / 10) {
      no();
      return;
    }
  }
  yes();
}
