#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();
  auto s = input<vector<string>>(n);

  ranges::sort(s, [](const auto& a, const auto& b) { return a + b < b + a; });

  vector dp(n + 1, vector<string>(k + 1, "~"));
  dp[0][0] = "";
  rep (i, n) {
    rep (l, k) {
      rep (j, i + 1) {
        chmin(dp[i + 1][l + 1], s[n - i - 1] + dp[j][l]);
      }
    }
  }

  string ans = "~";
  rep (i, n) chmin(ans, dp[i + 1][k]);
  output(ans);
}
