#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/io.hpp"
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>();
  auto G = input<Grid>(h, w);
  auto sx = input<int>() - 1, sy = input<int>() - 1;
  auto gx = input<int>() - 1, gy = input<int>() - 1;

  vector d(h, vector(w, INF));
  deque<pair<int, int>> Q;
  d[sx][sy] = 0;
  Q.emplace_back(sx, sy);
  while (!Q.empty()) {
    auto [x, y] = Q.front();
    Q.pop_front();
    for (auto [x2, y2]: G.neighbors4(x, y)) {
      if (G[x2][y2] == '.') {
        if (chmin(d[x2][y2], d[x][y])) {
          Q.emplace_front(x2, y2);
        }
      }
      else {
        int dx = x2 - x, dy = y2 - y;
        rep (_, 2) {
          if (G.contains(x2, y2) && chmin(d[x2][y2], d[x][y] + 1)) {
            Q.emplace_back(x2, y2);
          }
          x2 += dx;
          y2 += dy;
        }
      }
    }
  }
  output(d[gx][gy]);
}
