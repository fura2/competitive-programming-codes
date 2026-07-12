#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int m = input<int>();
  vector<int> R(m), C(m);
  rep (i, m) {
    R[i] = input<int>() - 1;
    C[i] = input<int>() - 1;
  }

  int ans = 0;
  vector<bool> used_r(n), used_c(n);
  rrep (i, m) {
    if (!used_r[R[i]] && !used_c[C[i]]) ans++;
    used_r[R[i]] = true;
    used_c[C[i]] = true;
  }
  output(ans);
}
