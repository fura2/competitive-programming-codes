#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto m = input<int>();
  auto a = input<vector<lint>>(m);

  a.resize(63);

  auto check = [&](lint th) {
    lint cur = 0;
    rrep (i, 63) {
      if (cur >= 2e6) break;
      if (bit(th, i)) cur += n;
      if (a[i] > cur) return false;
      cur -= a[i];
      cur *= 2;
    }
    return true;
  };

  lint wsum = 0;
  rep (i, m) wsum += a[i] << i;

  lint lo = -1, hi = wsum;
  while (hi - lo > 1) {
    lint mi = (lo + hi) / 2;
    (check(mi) ? hi : lo) = mi;
  }
  output(hi);
}
