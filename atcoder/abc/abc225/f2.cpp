#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();
  auto s = input<vector<string>>(n);

  ranges::sort(s, [](const auto& a, const auto& b) { return a + b < b + a; });

  vector<string> dp(k + 1, "~"), ndp;
  dp[0] = "";
  rep (i, n) {
    ndp = dp;
    rep (j, k) {
      chmin(ndp[j + 1], s[n - i - 1] + dp[j]);
    }
    swap(dp, ndp);
  }
  output(dp[k]);
}
