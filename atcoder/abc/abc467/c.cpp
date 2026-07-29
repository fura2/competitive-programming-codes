#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int m = input<int>();
  auto a = input<vector<int>>(n);
  auto b = input<vector<int>>(n - 1);

  int ans = INF;
  rep (k, 2) {
    int res = k;
    auto c = a;
    rep (i, n - 1) {
      if ((c[i] + c[i + 1]) % 2 != b[i]) {
        c[i + 1]++;
        res++;
      }
    }
    a[0]++;
    chmin(ans, res);
  }
  output(ans);
}
