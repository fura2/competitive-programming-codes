#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int h = input<int>();
  int w = input<int>();
  int k = input<int>();
  auto B = input<vector<string>>(h);

  vector cum(h + 1, vector(w + 1, 0));
  rep (i, h)
    rep (j, w) cum[i + 1][j + 1] = B[i][j] - '0';
  rep (i, h)
    rep (j, w + 1) cum[i + 1][j] += cum[i][j];
  rep (i, h + 1)
    rep (j, w) cum[i][j + 1] += cum[i][j];

  // 和が k 以下を数える
  auto f = [&](int k) -> lint {
    if (k < 0) return 0;
    lint res = 0;
    vector<lint> a(w);
    rep (t, h) {
      rep (b, t + 1, h + 1) {
        rep (j, w) a[j] = cum[b][j + 1] - cum[b][j] - cum[t][j + 1] + cum[t][j];
        int r = 0;
        int sum = 0;
        rep (l, w) {
          while (r < w && sum + a[r] <= k) {
            sum += a[r];
            r++;
          }
          res += r - l;
          sum -= a[l];
        }
      }
    }
    return res;
  };

  output(f(k) - f(k - 1));
}
