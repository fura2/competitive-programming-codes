#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/lint_add_group.hpp"
#include "data_structure/fenwick_tree.hpp"
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int q = input<int>();
  auto a = input<vector<lint>>(n);

  FenwickTree<LintAddGroup> F(a);
  rep (_, q) {
    int t = input<int>();
    int l = input<int>();
    int r = input<int>();
    if (t == 0)
      F.apply(l, r);
    else
      output(F.fold(l, r).unwrap());
  }
}
