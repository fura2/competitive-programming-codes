#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/double_min_monoid.hpp"
#include "data_structure/segment_tree.hpp"
#include "template/main.hpp"

bool f(int n, int k, const string& s, double th) {
  vector<double> a(n);
  rep (i, n) {
    a[i] = (s[i] == 'o' ? 1 : 0) - th;
  }

  double sum = 0;
  int cnt = 0;
  SegmentTree<DoubleMinMonoid> S(n + 1);
  S.set(0, 0.0);
  rep (i, n) {
    sum += a[i];
    if (s[i] == 'o') cnt++;
    S.set(cnt, S.get(cnt) * sum);
    if (cnt >= k) {
      if (sum - S.fold(0, cnt - k + 1).unwrap() > 0) return true;
    }
  }
  return false;
}

void testcase() {
  int n = input<int>();
  int k = input<int>();
  auto s = input<string>();

  double lo = 0, hi = 1;
  rep (_, 20) {
    double mi = (lo + hi) / 2;
    if (f(n, k, s, mi))
      lo = mi;
    else
      hi = mi;
  }
  output(hi);
}
