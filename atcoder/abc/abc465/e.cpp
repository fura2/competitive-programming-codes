#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "mint/mint.hpp"
#include "template/main.hpp"

string s;

bool vis[502][2][2][3][2][1024];
mint memo[502][2][2][3][2][1024];

mint dfs(int i, bool smaller, bool z, int mod3, bool has3, int S) {
  mint& res = memo[i][smaller][z][mod3][has3][S];
  if (vis[i][smaller][z][mod3][has3][S]) {
    return res;
  }
  vis[i][smaller][z][mod3][has3][S] = true;

  if (i == s.size()) {
    int cnt = 0;
    if (mod3 == 0) cnt++;
    if (has3) cnt++;
    if (popcount(unsigned(S)) == 3) cnt++;
    return res = (cnt == 1 ? 1 : 0);
  }

  res = 0;
  rep (d, 10) {
    if (!smaller && s[i] - '0' < d) continue;
    res += dfs(i + 1,
               smaller || d < s[i] - '0',
               z && d == 0,
               (mod3 * 10 + d) % 3,
               has3 || d == 3,
               (z && d == 0) ? 0 : (S | (1 << d)));
  }
  return res;
}

void testcase() {
  s = input<string>();
  output(dfs(0, false, true, 0, false, 0) - 1);
}
