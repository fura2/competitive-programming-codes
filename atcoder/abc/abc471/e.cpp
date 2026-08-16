#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "mint/mint.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();
  auto a = input<vector<mint>>(n);

  mint sum = 0, sqsum = 0;
  rep (i, n) {
    sum += a[i];
    sqsum += a[i] * a[i];
  }
  mint cross = (sum * sum - sqsum) / 2;

  mint ans = choose(n - 1, k - 1) * sqsum;
  if (k >= 2) {
    ans += 2 * choose(n - 2, k - 2) * cross;
  }
  output(ans);
}
