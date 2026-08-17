#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<lint>(), m = input<lint>();
  lint x = 0, npow = 1;
  rep (i, m + 1) {
    x += npow;
    if (x > lint(1e9)) {
      output("inf");
      return;
    }
    npow *= n;
  }
  output(x);
}
