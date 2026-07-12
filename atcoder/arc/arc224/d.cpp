#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto k = input<int>();

  lint ans = 0;
  if (n >= k - 1) {
    rep (i, 1, k) ans += to_string(i).size();
  }
  else {
    k--;
    rep (i, 1, n + 1) {
      __int128_t t = 1;
      rep (j, i) t *= n - j;
      rep (j, i) t /= j + 1;
      lint c = t;

      rep (j, c) {
        if (k == 0) break;
        ans += i * to_string(k).size();
        k--;
      }
      if (k == 0) break;
    }
    if (k > 0) ans = -1;
  }
  output(ans);
}
