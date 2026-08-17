#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<string>(), b = input<string>(), c = input<string>();

  vector<int> p, q, r;
  rep (i, 2 * n) {
    if (a[i] == '1') p.emplace_back(i);
    if (b[i] == '1') q.emplace_back(i);
    if (c[i] == '1') r.emplace_back(i);
  }

  lint ans = 0;
  string x(2 * n, '0');
  rep (i, n) {
    int s[3] = {p[i], q[i], r[i]};
    ranges::sort(s);
    x[s[1]] = '1';
    ans += abs(p[i] - s[1]) + abs(q[i] - s[1]) + abs(r[i] - s[1]);
  }
  output(ans);
  output(x);
}
