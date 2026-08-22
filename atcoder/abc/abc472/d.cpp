#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>(), k = input<int>();
  auto G = input<Grid>(h, w);

  vector<int> rsum(h), csum(w);
  rep (i, h) {
    rep (j, w) {
      if (G[i][j] == '#') {
        rsum[i]++;
        csum[j]++;
      }
    }
  }

  vector d(h, vector(w, -1));
  queue<pair<int, int>> Q;
  rep (i, h) {
    rep (j, w) {
      if (rsum[i] == 0 && csum[j] == 0) {
        d[i][j] = 0;
        Q.emplace(i, j);
      }
    }
  }
  int ans = 0;
  while (!Q.empty()) {
    auto [x, y] = Q.front();
    Q.pop();
    ans++;
    if (d[x][y] == k) continue;
    for (auto [x2, y2]: G.neighbors4(x, y)) {
      if (G[x2][y2] == '.' && d[x2][y2] == -1) {
        d[x2][y2] = d[x][y] + 1;
        Q.emplace(x2, y2);
      }
    }
  }
  output(ans);
}
