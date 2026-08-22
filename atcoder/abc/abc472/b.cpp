#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  int ans = INF;
  rep (i, n - 1) {
    int l = 0, r = 0;
    rep (j, n) (j <= i ? l : r) += a[j];
    chmin(ans, abs(l - r));
  }
  output(ans);
}
