#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto k = input<lint>() - 1;
  vector<vector<int>> a(n);
  rep (i, n) {
    auto l = input<int>();
    a[i] = input<vector<int>>(l);
  }
  auto c = input<vector<int>>(n);

  rep (i, n) {
    if (k < c[i] * a[i].size()) {
      output(a[i][k % a[i].size()]);
      return;
    }
    k -= c[i] * a[i].size();
  }
}
