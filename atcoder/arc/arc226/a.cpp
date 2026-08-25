#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "mint/mint.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  vector<int> l(n), r(n);
  rep (i, n) {
    l[i] = input<int>() - 1;
    r[i] = input<int>() - 1;
  }

  vector<int> cum(2 * n + 1);
  rep (i, n) {
    cum[l[i]]++;
    cum[r[i]]--;
  }
  rep (i, 2 * n) {
    cum[i + 1] += cum[i];
  }
  rep (i, 2 * n + 1) {
    if (cum[i] >= 3) {
      output(0);
      return;
    }
  }

  int cnt = 0;
  rep (i, 2 * n + 1) {
    if ((i == 0 || (i > 0 && cum[i - 1] == 0)) && cum[i] > 0) cnt++;
  }
  output(pow(mint(2), cnt));
}
