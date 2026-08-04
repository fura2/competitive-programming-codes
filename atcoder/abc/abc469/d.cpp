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

  vector<int> deg(n);
  rep (i, m) {
    deg[a[i]]++;
    deg[b[i]]++;
  }

  set<pair<int, int>> ans;
  rep (u, n) {
    if (deg[u] < (m + 1) / 2) continue;

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
