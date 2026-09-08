#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "mint/mint.hpp"
#include "template/main.hpp"

void testcase() {
  auto x1 = input<lint>(), x2 = input<lint>(), x3 = input<lint>();

  mint ans = 0;
  rep (a, 1, min(x1, x2 + 1) + 1)
    ans += choose(x2 + 1, a) * multichoose(a, x1 - a) *
           multichoose(x2 + 1 - a, x3);
  output(ans);
}
