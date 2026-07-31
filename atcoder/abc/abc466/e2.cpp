// greedy solution

#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

lint greedy(vector<lint>& a) {
  int n = a.size();
  vector<lint> dp(n + 1, -LINF), pre(n + 1, -1);
  rep (i, n) {
    dp[i + 1] = a[i];
    if (chmax(dp[i + 1], dp[i] + a[i])) {
      pre[i + 1] = i;
    }
  }

  int i_max = max_element(dp.begin(), dp.end()) - dp.begin();
  int i = i_max;
  while (pre[i] != -1) i = pre[i];
  rep (j, i - 1, i_max) a[j] *= -1;
  return dp[i_max];
}

void testcase() {
  int n = input<int>();
  int k = input<int>();
  vector<lint> a(n), b(n), c(n);
  rep (i, n) {
    a[i] = input<lint>();
    b[i] = input<lint>();
    c[i] = b[i] - a[i];
  }

  lint ans = reduce(a.begin(), a.end());
  rep (_, k) {
    lint d = greedy(c);
    if (d < 0) break;
    ans += d;
  }
  output(ans);
}
