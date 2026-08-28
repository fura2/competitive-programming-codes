#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/isqrt.hpp"

void testcase() {
  auto n = input<lint>();

  lint m = isqrt(n);

  lint ans = 2 * (m - 1) * m;
  lint k = n - m * m;
  if (k <= m) {
    if (k > 0) ans += k + (k - 1);
  }
  else {
    ans += m + (m - 1);
    k -= m;
    if (k > 0) ans += k + (k - 1);
  }
  output(ans);
}
