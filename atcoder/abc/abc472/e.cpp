#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
  G[u].emplace_back(v);
  G[v].emplace_back(u);
}

void testcase() {
  auto n = input<int>(), m = input<int>();
  graph G(n);
  rep (i, m) {
    auto u = input<int>() - 1, v = input<int>() - 1;
    add_undirected_edge(G, u, v);
  }

  vector<int> color(n, -1), path, ans;
  auto dfs = [&](auto&& dfs, int u, int c) -> bool {
    color[u] = c;
    path.emplace_back(u);
    for (int v: G[u]) {
      if (color[v] == c) {
        ans = {v};
        while (path.back() != v) {
          ans.emplace_back(path.back());
          path.pop_back();
        }
        return true;
      }
      else if (color[v] == -1) {
        if (dfs(dfs, v, 1 - c)) return true;
      }
    }
    path.pop_back();
    return false;
  };
  rep (u, n) {
    if (color[u] != -1) continue;
    path.clear();
    ans.clear();
    if (dfs(dfs, u, 0)) {
      output(ans.size());
      output(ans, 1);
      return;
    }
  }
  output(-1);
}
