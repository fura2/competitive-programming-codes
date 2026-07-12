#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  auto x = input<vector<int>>(n);
  bool ok = true;
  rep (i, n)
    if (x[i] >= 0) ok = false;
  yesno(ok);
}
