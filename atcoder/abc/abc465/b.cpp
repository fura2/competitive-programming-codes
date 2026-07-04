#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int x = input<int>();
  int y = input<int>();
  int l = input<int>();
  int r = input<int>();
  int a = input<int>();
  int b = input<int>();

  int ans = 0;
  rep (i, a, b) {
    if (l <= i && i < r)
      ans += x;
    else
      ans += y;
  }
  output(ans);
}
