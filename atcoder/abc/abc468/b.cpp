#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int d = input<int>();
  auto s = input<string>();

  rep (i, n) {
    if (s[i] == 'G') {
      rep (j, -d, d + 1) {
        int k = i + j;
        if (0 <= k && k < n && s[k] == '.') s[k] = 'x';
      }
    }
  }

  output(ranges::count(s, '.'));
}
