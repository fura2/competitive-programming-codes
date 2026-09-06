#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<lint>>(n);

  lint ans = 0;
  rep (i, n - 1) {
    if (a[i] < 2 * a[i + 1]) {
      output(-1);
      return;
    }
    chmax(ans, a[i] - 2 * a[i + 1]);
  }
  if (a[n - 1] > 0) chmax(ans, 1LL);
  output(ans);
}
