#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "mint/mint.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  vector<mint> cum(n + 1);
  rep (i, n) cum[i + 1] = cum[i] + a[i];

  mint ans = 0, sum = 0;
  rep (d, 1, (n + 1) / 2 + 1) {
    sum += cum[n - d + 1] - cum[d - 1];
    ans += sum / mint(d);
    if (!(n % 2 == 1 && d == (n + 1) / 2)) {
      ans += sum / mint(n - d + 1);
    }
  }
  output(ans);
}
