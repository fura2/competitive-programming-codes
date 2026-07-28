#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/int_add_group.hpp"
#include "data_structure/fenwick_tree.hpp"
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int q = input<int>();

  vector pre(2, vector(n, -1));
  FenwickTree<IntAddGroup> F[2] = {auto(q), auto(q)};  // row, col
  lint ans = 0;
  rep (i, q) {
    int t = input<int>() - 1;
    int a = input<int>() - 1;

    int k = pre[t][a];
    if (t == 0) {
      if (k == -1)
        ans += n;
      else
        ans += F[1].fold(k + 1, i).unwrap();
    }
    else {
      ans -= F[0].fold(k + 1, i).unwrap();
    }
    output(ans);

    if (k != -1) F[t].apply(k, -1);  // F[t][k] に立てていた 1 をキャンセル
    F[t].apply(i, 1);

    pre[t][a] = i;
  }
}
