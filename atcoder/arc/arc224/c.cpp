#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
  G[u].emplace_back(v);
  G[v].emplace_back(u);
}

void testcase() {
  auto n = input<int>();
  auto m = input<int>();
  graph G(n);
  rep (i, m) {
    int u = input<int>() - 1;
    int v = input<int>() - 1;
    add_undirected_edge(G, u, v);
  }

  vector<int> d(n, -1);
  auto dfs = [&](auto dfs, int u) -> void {
    for (int v: G[u]) {
      if (d[v] != -1) continue;
      d[v] = d[u] + 1;
      dfs(dfs, v);
    }
  };
  d[0] = 0;
  dfs(dfs, 0);

  output(d);
}
