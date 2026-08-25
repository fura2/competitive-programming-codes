#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto m = input<int>();
  auto a = input<vector<lint>>(m);

  a.resize(63);

  auto check = [&](lint th) {
    auto b = a;
    rep (i, 62) {
      if (bit(th, i)) {
        b[i] = max(b[i] - n, 0LL);
      }
      b[i + 1] += (b[i] + 1) / 2;
      b[i] = 0;
    }
    return ranges::all_of(b, [](auto x) { return x == 0; });
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
