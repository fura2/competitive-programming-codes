#include "template/template.hpp"

#define MULTI_TESTCASE
#include "data_structure/union_find.hpp"
#include "graph/weighted_graph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto G = input<WeightedGraph<int>>(n, m, 1);

  UnionFind U1(n), U2(n), U3(n);
  rep (i, m) {
    auto e = G.edge(i);
    int u = e.from, v = e.to;
    if (e.cost == 1) U1.unite(u, v);
    if (e.cost == 2) U2.unite(u, v);
    if (e.cost == 3) U3.unite(u, v);
  }

  map<int, vector<int>> f;
  for (auto cc: U2.groups()) {
    f.clear();
    for (int u: cc) {
      f[U3.find(u)].emplace_back(u);
    }
    for (const auto& [r, vs]: f) {
      for (int v: vs) U1.unite(vs[0], v);
    }
  }

  auto ans = U1.group(0);
  output(ans.size());
  output(ans, 1);
}
