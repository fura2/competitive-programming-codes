#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "mint/mint.hpp"
#include "template/main.hpp"

mint f(vector<int> p, vector<int> q) {
  int n = p.size();
  ranges::reverse(q);
  mint res = 0;
  rep (i, n) {
    while (!q.empty() && q.back() < p[i]) q.pop_back();
    int m = q.size();
    // int k = min(i + 1, m);
    // rep (j, 1, k + 1) res += choose(i, j - 1) * choose(m, j);
    if (m > 0) res += choose(i + m, min(i + 1, m - 1));
  }
  return res;
}

void testcase() {
  auto s = input<string>();
  int n = s.size();

  vector pos(11, vector<int>());
  rep (i, n) pos[s[i] - '0'].emplace_back(i);

  mint ans = 0;
  rep (d, 9) ans += f(pos[d], pos[d + 1]);
  output(ans);
}
