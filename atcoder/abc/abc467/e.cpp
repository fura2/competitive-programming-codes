#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  auto m = input<lint>();
  auto a = input<vector<lint>>(n);
  auto b = input<vector<lint>>(n - 1);

  vector<lint> d(n);
  {
    auto c = a;
    rep (i, 1, n) {
      d[i] = (b[i - 1] - (c[i - 1] + c[i]) % m + m) % m;
      c[i] = (c[i] + d[i]) % m;
    }
  }
  lint cost = accumulate(d.begin(), d.end(), 0LL);

  vector<lint> c = {0};  // a[0] の操作回数の候補
  rep (i, 1, n) {
    if (i % 2 == 0) {  // +
      c.emplace_back(m - d[i]);
    }
  }
  ranges::sort(c);
  c.erase(ranges::unique(c).begin(), c.end());

  vector<lint> Plus, Minus;
  rep (i, 1, n) {
    if (i % 2 == 1) {  // -
      Minus.emplace_back(d[i]);
    }
    else {  // +
      Plus.emplace_back(d[i]);
    }
  }
  ranges::sort(Plus, greater());
  ranges::sort(Minus);

  lint ans = LINF;
  int im = 0, ip = 0;
  for (lint t: c) {
    lint res = cost + t - t * ssize(Minus) + t * ssize(Plus);
    while (im < Minus.size() && t > Minus[im]) {
      im++;
    }
    while (ip < Plus.size() && t >= m - Plus[ip]) {
      ip++;
    }
    res += im * m;
    res -= ip * m;
    chmin(ans, res);
  }
  output(ans);
}
