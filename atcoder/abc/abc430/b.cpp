#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto B = input<Grid>(n, m);

  set<string> S;
  rep (i, n - m + 1) {
    rep (j, n - m + 1) {
      string s;
      rep (x, m)
        rep (y, m) s += B[i + x][j + y];
      S.emplace(s);
    }
  }
  output(S.size());
}
