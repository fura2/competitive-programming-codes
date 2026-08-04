#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int m = input<int>();
  vector<int> a(m), b(m);
  rep (i, m) {
    a[i] = input<int>() - 1;
    b[i] = input<int>() - 1;
  }

  set<pair<int, int>> ans;
  for (int u: {a[0], b[0]}) {
    int sz = 0;
    vector<int> h(n);
    rep (i, m) {
      if (a[i] == u || b[i] == u) continue;
      h[a[i]]++;
      h[b[i]]++;
      sz++;
    }
    rep (v, n) {
      if (v != u && h[v] == sz) {
        ans.emplace(minmax(u, v));
      }
    }
  }
  output(ans.size());
}
