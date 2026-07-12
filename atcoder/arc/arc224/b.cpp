#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<lint>();

  lint m = sqrt(n) + 2;
  while (m * m > n) m--;

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
