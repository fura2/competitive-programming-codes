#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto k = input<lint>();

  lint ans = 100 * k;
  rep (i, 99) {
    string s = to_string((i + 1) * k);
    bool ok = false;
    rep (i, s.size() - 1)
      if (s[i] == '0' && s[i + 1] == '0') ok = true;
    if (ok) chmin(ans, (i + 1) * k);
  }
  output(ans);
}
