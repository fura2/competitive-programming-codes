#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), mod = input<int>();
  auto a = input<vector<int>>(n);

  vector<int> dp(n + 1, -INF);
  dp[0] = 0;
  map<int, int> pos;
  int cum = 0;
  rep (i, n) {
    dp[i + 1] = dp[i];
    pos[cum] = i;
    cum = (cum + a[i]) % mod;
    if (pos.contains(cum)) {
      chmax(dp[i + 1], dp[pos[cum]] + 1);
    }
  }
  output(dp[n]);
}
