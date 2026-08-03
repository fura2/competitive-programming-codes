#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  ranges::sort(s);
  int n = s.size();
  rep (i, n) {
    if (s[i] != '0' && s[0] == '0') {
      swap(s[i], s[0]);
      break;
    }
  }
  output(s);
}
