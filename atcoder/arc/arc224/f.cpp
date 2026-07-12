#include "template/template.hpp"

#define MULTI_TESTCASE
#include "mint/mint.hpp"
#include "template/main.hpp"

// tar の立っている bit を全部 1 にできるか
bool check(const vector<lint>& a, int k, lint tar) {
  int n = a.size();
  rep (i, n) {
    if ((tar & a[i]) != tar) {
      if (k == 0) return false;
      k--;
      tar &= ~(tar & a[i]);
    }
    else {
      if (k == 0) return false;
      k--;
      return true;
    }
  }
  return tar == 0;
}

void testcase() {
  auto n = input<int>();
  auto k = input<int>();
  auto a = input<vector<lint>>(n);

  ranges::reverse(a);

  lint mx = 0;
  rrep (b, 60) {
    mx |= 1LL << b;
    if (!check(a, k, mx)) mx &= ~(1LL << b);
  }

  mint comb_sum = 0;
  rep (j, k) comb_sum += choose(n - 1, j);

  mint ans = 0;
  rep (i, n) {
    if (k == 0) break;
    if ((mx & a[i]) != mx) {
      comb_sum -= choose(n - i - 1, k - 1);
      k--;
      mx &= ~(mx & a[i]);
    }
    else {
      // rep (j, k) ans += choose(n - i - 1, j);
      ans += comb_sum;
    }
    if (k > 0) {
      comb_sum = (comb_sum + choose(n - i - 2, k - 1)) / 2;
    }
  }
  if (mx == 0) ans += 1;
  output(ans);
}
