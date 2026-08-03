#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto x = input<lint>(), y = input<lint>();
  auto a = input<vector<lint>>(n);

  ranges::sort(a, greater());

  vector<lint> d(n);
  rep (i, 1, n) {
    if ((a[0] - a[i]) * x % (y - x) != 0) {
      output(-1);
      return;
    }
    d[i] = (a[0] - a[i]) * x / (y - x);
    if (d[i] > a[i]) {
      output(-1);
      return;
    }
  }

  lint c = LINF;
  rep (i, n) {
    chmin(c, a[i] - d[i]);
  }
  output(reduce(d.begin(), d.end()) + n * c);
}
