#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  vector<lint> a(n), b(n);
  rep (i, n) {
    a[i] = input<lint>();
    b[i] = input<lint>();
  }

  vector<int> p(n);
  ranges::iota(p, 0);
  ranges::sort(p, [&](int i, int j) { return a[i] - b[i] < a[j] - b[j]; });

  lint amin = ranges::min(a);
  lint bsum = accumulate(b.begin(), b.end(), 0LL);

  lint ans = LINF;
  lint dsum = 0;
  rep (i, n + 1) {
    chmin(ans, bsum + dsum + max(n - 2 * i, 0) * amin);
    if (i < n) {
      dsum += a[p[i]] - b[p[i]];
    }
  }
  output(ans);
}
