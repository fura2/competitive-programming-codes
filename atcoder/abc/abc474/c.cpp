#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto p = input<vector<int>>(n, 1);

  vector<int> pos(n);
  rep (i, n) pos[p[i]] = i;
  rep (i, q) {
    int a = input<int>() - 1;
    p[pos[a]] = -1;
    p.emplace_back(a);
    pos[a] = n + i;
  }
  rep (i, n + q) {
    if (p[i] != -1) output(p[i] + 1);
  }
}
