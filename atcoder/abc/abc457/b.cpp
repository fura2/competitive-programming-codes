#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  vector<vector<int>> a(n);
  rep (i, n) {
    auto l = input<int>();
    a[i] = input<vector<int>>(l);
  }
  auto x = input<int>() - 1, y = input<int>() - 1;
  output(a[x][y]);
}
