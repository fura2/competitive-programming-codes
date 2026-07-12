#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int k = input<int>();
  int m = input<int>();
  vector<int> c(n);
  vector<lint> v(n);
  rep (i, n) {
    c[i] = input<int>() - 1;
    v[i] = input<lint>();
  }

  vector<int> p(n);
  ranges::iota(p, 0);
  ranges::sort(p, [&](int i, int j) { return v[i] > v[j]; });

  lint ans = 0;
  vector<bool> used(n);
  rep (i, n) {
    if (m == 0) break;
    if (used[c[p[i]]]) continue;
    used[c[p[i]]] = true;
    ans += v[p[i]];
    p[i] = -1;
    k--;
    m--;
  }
  rep (i, n) {
    if (k == 0) break;
    if (p[i] == -1) continue;
    ans += v[p[i]];
    k--;
  }
  output(ans);
}
