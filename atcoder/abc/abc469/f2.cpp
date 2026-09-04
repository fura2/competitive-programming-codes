#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "data_structure/union_find.hpp"
#include "number_theory/linear_sieve.hpp"
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  auto a = input<vector<int>>(n);

  int a_max = ranges::max(a);
  vector<vector<int>> idxs(a_max + 1);
  LinearSieve S(a_max);
  rep (u, n) {
    for (int d: S.divisors(a[u])) {
      idxs[d].emplace_back(u);
    }
  }

  lint ans = 0;
  UnionFind U(n);
  rrep (w, a_max + 1) {
    if (idxs[w].size() <= 1) continue;

    int u = U.find(idxs[w][0]);
    rep (i, 1, idxs[w].size()) {
      int v = U.find(idxs[w][i]);
      if (!U.same(u, v)) {
        U.unite(u, v);
        ans += w;
      }
    }
  }
  output(ans);
}
