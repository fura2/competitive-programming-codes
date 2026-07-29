#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int ans = 0;
  rep (i, n) {
    int a = input<int>();
    int b = input<int>();
    auto s = input<string>();
    if (s == "keep") ans += b - a;
  }
  output(ans);
}
