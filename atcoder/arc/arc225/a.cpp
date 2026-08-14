#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  vector<vector<int>> a(n);
  rep (i, n) a[i] = input<vector<int>>(n);

  int f[5] = {0, 2, 4, 1, 3};
  rep (i, n) {
    rep (j, n) {
      a[i][j] = f[a[i][j]];
    }
    output(a[i]);
  }
}
