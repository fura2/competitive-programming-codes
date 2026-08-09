#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/lint_min_monoid.hpp"
#include "data_structure/sparse_table.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  SparseTable<LintMinMonoid> S{a};
  lint ans = 0;
  rep (l, n) {
    rep (r, l + 1, n + 1) {
      chmax(ans, S.fold(l, r).unwrap() * (r - l));
    }
  }
  output(ans);
}
