#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int k = input<int>();
  vector<lint> a(n), b(n);
  rep (i, n) {
    a[i] = input<lint>();
    b[i] = input<lint>();
  }

  static lint dp[200001][11][2];
  rep (i, n + 1)
    rep (j, k + 1)
      rep (f, 2) dp[i][j][f] = -LINF;
  dp[0][k][0] = 0;
  rep (i, n) {
    rep (j, k + 1) {
      chmax(dp[i + 1][j][0], dp[i][j][0] + a[i]);
      chmax(dp[i + 1][j][1], dp[i][j][1] + b[i]);
      // ひっくり返す
      if (j > 0) {
        chmax(dp[i + 1][j - 1][1], dp[i][j][0] + b[i]);
      }
      chmax(dp[i + 1][j][0], dp[i][j][1] + a[i]);
    }
  }
  lint ans = -INF;
  rep (j, k + 1)
    rep (f, 2) chmax(ans, dp[n][j][f]);
  output(ans);
}
