#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>();
  rep (i, h) {
    rep (j, w) {
      int cnt = 0;
      if (i > 0) cnt++;
      if (i < h - 1) cnt++;
      if (j > 0) cnt++;
      if (j < w - 1) cnt++;
      output(cnt);
    }
  }
}
