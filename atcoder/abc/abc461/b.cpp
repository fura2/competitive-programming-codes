#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  auto p = input<vector<int>>(n, 1);
  auto q = input<vector<int>>(n, 1);

  vector<int> inv(n);
  rep (i, n) inv[p[i]] = i;
  yesno(inv == q);
}
