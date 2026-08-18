#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto w = input<lint>();
  vector<int> x(n);
  vector<lint> y(n);
  rep (i, n) {
    x[i] = input<int>();
    y[i] = input<lint>();
  }

  lint ans = 0;
  rep (b, 60) {
    vector<int> x2;
    vector<lint> y2;
    vector<int> I;
    rep (i, n) {
      if (x[i] == b) {
        I.emplace_back(i);
      }
      else if (x[i] > b) {
        x2.emplace_back(x[i]);
        y2.emplace_back(y[i]);
      }
    }
    ranges::sort(I, [&](int i, int j) { return y[i] > y[j]; });

    int idx = 0;
    if (bit(w, b) && !I.empty()) {
      ans += y[I[0]];
      idx++;
    }
    for (; idx < I.size(); idx += 2) {  // 大きいものから 2 個ずつペアにする
      x2.emplace_back(b + 1);
      y2.emplace_back(y[I[idx]] + (idx + 1 < I.size() ? y[I[idx + 1]] : 0));
    }
    n = x2.size();
    swap(x, x2);
    swap(y, y2);
  }
  output(ans);
}
