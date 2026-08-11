#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto c = input<vector<int>>(n, 1);

  vector<int> h(n);
  rep (i, n) h[c[i]]++;
  output(n - ranges::max(h));
}
