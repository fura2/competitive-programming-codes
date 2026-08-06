#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

struct Rect {
  lint t, l, b, r;
  lint area() const {
    return (b - t) * (r - l);
  }
  friend string pretty(const Rect& r) {
    return format("({}, {}, {}, {})", r.t, r.l, r.b, r.r);
  }
};

void testcase() {
  auto q = input<int>();
  auto h = input<lint>(), w = input<lint>();

  vector<Rect> R = {{0, 0, h, w}}, R2;
  rep (_, q) {
    auto c = input<char>();
    auto a = input<lint>(), b = input<lint>();

    R2.clear();
    if (c == 'X') {
      for (auto e: R) {
        if (e.b <= a) {
          R2.emplace_back(e.t, e.l - b, e.b, e.r - b);
        }
        else if (e.t >= a) {
          R2.emplace_back(e.t, e.l + b, e.b, e.r + b);
        }
        else {
          R2.emplace_back(e.t, e.l - b, a, e.r - b);
          R2.emplace_back(a, e.l + b, e.b, e.r + b);
        }
      }
    }
    else {
      for (auto e: R) {
        if (e.r <= a) {
          R2.emplace_back(e.t - b, e.l, e.b - b, e.r);
        }
        else if (e.l >= a) {
          R2.emplace_back(e.t + b, e.l, e.b + b, e.r);
        }
        else {
          R2.emplace_back(e.t - b, e.l, e.b - b, a);
          R2.emplace_back(e.t + b, a, e.b + b, e.r);
        }
      }
    }
    swap(R, R2);
  }

  vector<lint> ans;
  int n = R.size();
  vector<bool> vis(n);
  rep (u0, n) {
    if (vis[u0]) continue;
    vis[u0] = true;
    queue<int> Q;
    Q.emplace(u0);
    lint cnt = 0;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      cnt += R[u].area();
      rep (v, n) {
        if (vis[v]) continue;
        if (((R[u].l == R[v].r || R[v].l == R[u].r) &&
             (R[u].t < R[v].b && R[v].t < R[u].b))  // 左右で接する
            || ((R[u].t == R[v].b || R[v].t == R[u].b) &&
                (R[u].l < R[v].r && R[v].l < R[u].r)))  // 上下で接する
        {
          vis[v] = true;
          Q.emplace(v);
        }
      }
    }
    ans.emplace_back(cnt);
  }

  ranges::sort(ans);

  output(ans.size());
  output(ans);
}
