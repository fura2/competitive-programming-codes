#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto k = input<lint>();
  auto a = input<vector<lint>>(n);

  lint sum = 0;
  queue<int> Q;
  rep (i, n) {
    while (!Q.empty() && Q.front() <= i - m) {
      sum -= a[Q.front()];
      Q.pop();
    }
    if (sum + a[i] <= k) {
      Q.emplace(i);
      sum += a[i];
      yes();
    }
    else {
      no();
    }
  }
}
