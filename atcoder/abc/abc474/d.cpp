#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<lint>>(n);
  auto b = input<vector<lint>>(n);

  rep (i, n) {
    if (a[i] > b[i]) {
      yes();
      rep (j, n) {
        output(j == i ? lint(1e18) : 1);
      }
      return;
    }
  }
  no();
}
