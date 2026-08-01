#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  auto a = input<vector<int>>(n);

  int ans = 0;
  rep (i, n - 2)
    if (a[i] < a[i + 1] && a[i + 1] > a[i + 2]) ans++;
  output(ans);
}
