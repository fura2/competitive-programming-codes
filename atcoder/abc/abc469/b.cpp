#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  auto s = input<string>();

  int ans = 0;
  rep (i, n) {
    if ((i == 0 || s[i - 1] == 'x') && s[i] == 'x' &&
        (i == n - 1 || s[i + 1] == 'x'))
      ans++;
  }
  output(ans);
}
