#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void naive(int h, int w) {
  int n = h * w;
  queue<lint> Q;
  vector<int> d(1LL << n, -1);
  d[0] = 0;
  Q.emplace(0);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    rep (i, h - 1) {
      rep (j, w - 1) {
        rep (s, 1, min(h, w) + 1) {
          if (i + s >= h || j + s >= w) continue;
          if (bit(u, i * w + j)) continue;
          if (bit(u, (i + s) * w + j)) continue;
          if (bit(u, i * w + (j + s))) continue;
          if (bit(u, (i + s) * w + (j + s))) continue;
          int v = u;
          v |= 1LL << ((i)*w + (j));
          v |= 1LL << ((i)*w + (j + s));
          v |= 1LL << ((i + s) * w + (j));
          v |= 1LL << ((i + s) * w + (j + s));
          if (d[v] == -1) {
            d[v] = d[u] + 1;
            Q.emplace(v);
          }
        }
      }
    }
  }
  int d_max = ranges::max(d);
  rep (u, 1LL << n) {
    if (d[u] != d_max) continue;
    int cnt = 0;
    rep (i, h) {
      string s;
      rep (j, w) {
        if (bit(u, i * w + j)) {
          s += 'o';
          cnt++;
        }
        else
          s += '.';
      }
      output(s);
    }
    show(cnt);
  }
}

void testcase() {
  auto h = input<int>(), w = input<int>();

  // naive(h, w);
  // return;

  vector<tuple<int, int, int>> ans;

  if (h % 2 == 0 || w % 2 == 0) {
    rep (i, 0, h / 2 * 2, 2) {
      rep (j, 0, w / 2 * 2, 2) {
        ans.emplace_back(i, j, 1);
      }
    }
  }
  else {
    // n x n -> (n+4) x (n+4)
    auto enclose = [](int n, vector<tuple<int, int, int>> t) {
      vector<tuple<int, int, int>> res;
      res.emplace_back(0, 0, n + 3);
      rep (k, (n + 1) / 2) {
        res.emplace_back(0, 2 + 2 * k, 1);
        res.emplace_back(2 + n, 1 + 2 * k, 1);
        res.emplace_back(1 + 2 * k, 0, 1);
        res.emplace_back(2 + 2 * k, 2 + n, 1);
      }
      for (auto [i, j, s]: t) {
        res.emplace_back(2 + i, 2 + j, s);
      }
      return res;
    };

    int n = min(h, w);
    if (n % 4 == 1) {  // 1, 5, 9, ...
      // nop
    }
    else {  // 3, 7, ...
      ans.emplace_back(0, 0, 1);
    }
    rep (i, n / 4) {
      ans = enclose(n % 4 + 4 * i, ans);
    }
    if (h < w) {
      rep (i, 0, h / 2 * 2, 2) {
        rep (j, h, w, 2) {
          ans.emplace_back(i, j, 1);
        }
      }
    }
    else if (w < h) {
      rep (j, 0, w / 2 * 2, 2) {
        rep (i, w, h, 2) {
          ans.emplace_back(i, j, 1);
        }
      }
    }
  }

  output(ans.size());
  for (auto [i, j, s]: ans) {
    output(format("{} {} {}", i + 1, j + 1, s));
  }

  // vector B(h, string(w, '.'));
  // for (auto [i, j, s]: ans) {
  //   show(i, j, s);
  //   assert(B[i][j] == '.');
  //   assert(B[i][j + s] == '.');
  //   assert(B[i + s][j] == '.');
  //   assert(B[i + s][j + s] == '.');
  //   B[i][j] = 'o';
  //   B[i][j + s] = 'o';
  //   B[i + s][j] = 'o';
  //   B[i + s][j + s] = 'o';
  // }
  // rep (i, h) output(B[i]);
}
