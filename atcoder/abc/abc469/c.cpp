#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  auto s = input<string>();

  int pos = 0, good = 0;
  rep (i, n) {
    if (pos < n) {
      if (s[pos] == 'o') good++;
      pos++;
      while (pos < n && good > 0) {
        good--;
        if (s[pos] == 'o') good++;
        pos++;
      }
    }
    output(pos);
  }
}
