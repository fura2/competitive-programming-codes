#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto x = input<int>(), n = input<int>();
  auto w = input<vector<int>>(n);
  auto q = input<int>();
  vector<bool> b(n);
  rep (_, q) {
    auto p = input<int>() - 1;
    if (b[p]) {
      x -= w[p];
      b[p] = false;
    }
    else {
      x += w[p];
      b[p] = true;
    }
    output(x);
  }
}
