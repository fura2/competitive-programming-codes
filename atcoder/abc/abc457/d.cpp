#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto k = input<lint>();
  auto a = input<vector<lint>>(n);

  lint lo = *ranges::min_element(a), hi = 2.1e18;
  while (hi - lo > 1) {
    lint mi = (lo + hi) / 2;
    bool ok = true;
    lint cnt = 0;
    rep (i, n) {
      cnt += (max(mi - a[i], 0LL) + i) / (i + 1);
      if (cnt > k) {
        ok = false;
        break;
      }
    }
    (ok ? lo : hi) = mi;
  }
  output(lo);
}
