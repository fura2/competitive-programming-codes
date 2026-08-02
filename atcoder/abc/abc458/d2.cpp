// verify FenwickTree::max_right and FenwickTree::min_left

#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/int_add_group.hpp"
#include "data_structure/fenwick_tree.hpp"
#include "template/main.hpp"

void testcase() {
  auto x = input<int>();
  auto q = input<int>();
  vector<pair<int, int>> p(q);
  rep (i, q) p[i] = input<pair<int, int>>();

  vector<int> X = {x};
  for (auto [a, b]: p) {
    X.emplace_back(a);
    X.emplace_back(b);
  }
  ranges::sort(X);
  X.erase(ranges::unique(X).begin(), X.end());
  int m = X.size();
  auto f = [&](int v) { return ranges::lower_bound(X, v) - X.begin(); };

  FenwickTree<IntAddGroup> F(m);
  F.apply(f(x), 1);
  rep (i, q) {
    auto [a, b] = p[i];
    F.apply(f(a), 1);
    F.apply(f(b), 1);
    int res1 = F.max_right([&](auto v) { return v.unwrap() <= i + 1; });
    int res2 = F.min_left(m, [&](auto v) { return v.unwrap() <= i + 1; }) - 1;
    assert(res1 == res2);
    output(X[res1]);
  }
}
