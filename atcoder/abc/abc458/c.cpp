#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();

  lint ans = 0;
  rep (i, n) {
    if (s[i] != 'C') continue;
    ans += min(i + 1, n - i);
  }
  output(ans);
}
