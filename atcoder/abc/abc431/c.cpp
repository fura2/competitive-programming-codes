#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>(), k = input<int>();
  auto a = input<vector<int>>(n);
  auto b = input<vector<int>>(m);
  ranges::sort(a);
  ranges::sort(b);

  int ans = 0, j = 0;
  rep (i, n) {
    while (j < m && a[i] > b[j]) j++;
    if (j == m) break;
    ans++;
    j++;
  }
  yesno(ans >= k);
}
