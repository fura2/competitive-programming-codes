#include "template/template.hpp"

// #define MULTI_TESTCASE
#include <atcoder/all>

#include "template/main.hpp"

using namespace atcoder;

using mint = modint998244353;

void testcase() {
  auto n = input<int>();
  auto k = input<lint>();

  if (k >= 2 * n) {
    output(0);
    return;
  }

  int m = bit_ceil<uint>(n - 1);
  vector<vector<mint>> spt(2 * m);  // subproduct tree
  rep (i, m) {
    if (i < n - 1)
      spt[m + i] = {1, n - i - 1};
    else
      spt[m + i] = {1};
  }
  rrep (i, 1, m) {
    spt[i] = convolution(spt[2 * i], spt[2 * i + 1]);
  }

  mint denom = 1;
  rep (i, n) denom *= i + 1;

  output((spt[1][k - n] / denom).val());
}
