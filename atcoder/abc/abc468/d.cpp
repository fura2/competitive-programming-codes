#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();

  int ans = 0;
  // odd
  rep (i, n) {
    int bad = 0;
    rep (d, n) {
      if (i - d < 0 || i + d >= n) break;
      if (s[i - d] != s[i + d]) bad++;
      if (bad >= 2) break;
      ans++;
    }
  }
  // even
  rep (i, n - 1) {
    int bad = 0;
    rep (d, 1, n) {
      if (i - d + 1 < 0 || i + d >= n) break;
      if (s[i - d + 1] != s[i + d]) bad++;
      if (bad >= 2) break;
      ans++;
    }
  }
  output(ans);
}
