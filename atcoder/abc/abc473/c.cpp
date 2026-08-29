#include "template/template.hpp"

#include <ranges>

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();
  auto a = input<vector<int>>(n, 1);

  vector<int> hist(k);
  rep (i, n) ++hist[a[i]];

  int ans = 0;
  int mx = ranges::max(hist);
  rep (i, k) {
    if (hist[i] >= mx - 1) ans++;
  }
  output(ans);
}
