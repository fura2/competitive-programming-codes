#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

lint knapsack_01(const vector<int>& ws, const vector<lint>& vs, const int cap) {
  auto n = ws.size();
  assert(n == vs.size());
  vector<lint> dp(cap + 1);
  rep (i, n) {
    if (vs[i] <= 0) continue;
    rrep (j, cap - ws[i] + 1) {
      chmax(dp[j + ws[i]], dp[j] + vs[i]);
    }
  }
  return *ranges::max_element(dp);
}

void testcase() {
  auto n = input<int>();
  vector<int> w(n);
  vector<lint> a(n), b(n);
  rep (i, n) {
    w[i] = input<int>();
    a[i] = input<lint>();
    b[i] = input<lint>();
  }

  int wsum = reduce(w.begin(), w.end());
  lint bsum = reduce(b.begin(), b.end());
  vector<int> W(n);
  vector<lint> V(n);
  rep (i, n) {
    W[i] = 2 * w[i];
    V[i] = a[i] - b[i];
  }
  output(bsum + knapsack_01(W, V, wsum));
}
