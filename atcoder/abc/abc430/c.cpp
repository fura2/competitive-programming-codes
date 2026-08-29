#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), a = input<int>(), b = input<int>();
  auto s = input<string>();

  lint ans = 0;
  int ra = 0, ca = 0;
  int rb = 0, cb = 0;
  rep (l, n) {
    while (ra < n && ca < a) {
      if (s[ra] == 'a') ca++;
      ra++;
    }
    if (ca < a) break;

    while (rb < n) {
      if (s[rb] == 'b') {
        if (cb + 1 >= b) break;
        cb++;
      }
      rb++;
    }

    ans += max(rb - ra + 1, 0);
    if (s[l] == 'a') ca--;
    if (s[l] == 'b') cb--;
  }
  output(ans);
}
