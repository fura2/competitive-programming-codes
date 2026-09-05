#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<lint>>(n);

  lint asum = accumulate(a.begin(), a.end(), 0LL);

  vector<lint> E, O;
  rep (i, n) {
    (a[i] % 2 == 0 ? E : O).emplace_back(a[i]);
  }
  ranges::sort(E, greater<lint>());
  ranges::sort(O, greater<lint>());

  lint ans = LINF;
  if (E.size() >= 2) {
    lint x = E[0], y = E[1];
    lint k = E.size() - 1;  // even の間の隙間の個数
    // 隙間に odd を挟むたびに、パリティが異なる隣接ペアは 2 増える
    lint c = 2 * min<lint>(O.size(), k);
    chmin(ans, asum - (x + y + c) / 2);
  }
  if (O.size() >= 2) {
    lint x = O[0], y = O[1];
    lint k = O.size() - 1;
    lint c = 2 * min<lint>(E.size(), k);
    chmin(ans, asum - (x + y + c) / 2);
  }
  if (E.size() >= 1 && O.size() >= 1) {
    lint x = E[0], y = O[0];
    lint k = E.size() - 1;
    lint c = 2 * min<lint>(O.size() - 1, k) + 1;
    chmin(ans, asum - (x + y + c) / 2);
  }
  output(ans);
}
