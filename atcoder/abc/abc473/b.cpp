#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);
  set<int> S;
  rep (i, n) {
    if (S.contains(a[i])) {
      S.erase(a[i]);
    }
    else {
      S.emplace(a[i]);
    }
  }

  int ans = 0;
  for (int x: S) ans += x;
  output(ans);
}
