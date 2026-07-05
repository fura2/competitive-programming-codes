// FoldableQueue の verify
#include "template/template.hpp"

#define MULTI_TESTCASE
#include "data_structure/foldable_queue.hpp"
#include "template/main.hpp"

struct M {
  array<array<lint, 2>, 2> a;

  M operator*(const M& m) const {
    return M(*this) *= m;
  }
  M& operator*=(const M& m) {
    M res;
    res.a = {{{LINF, LINF}, {LINF, LINF}}};
    rep (i, 2) {
      rep (j, 2) {
        rep (k, 2) {
          chmin(res.a[i][j], a[i][k] + m.a[k][j]);
        }
      }
    }
    return *this = res;
  }
  static M identity() {
    return {I};
  }

 private:
  static constexpr array<array<lint, 2>, 2> I = {{{0, LINF}, {LINF, 0}}};
};

void testcase() {
  int n = input<int>();
  int k = input<int>();
  auto a = input<vector<int>>(n);

  vector<M> b(n);
  rep (i, n) {
    b[i].a = {{{a[i], a[i]}, {0, LINF}}};
  }

  lint ans = LINF;
  FoldableQueue<M> Q;
  rep (i, n) {
    Q.push(b[i]);
    while (Q.size() > k) Q.pop();
    if (Q.size() == k) {
      auto x = Q.fold();
      chmin(ans, x.a[0][1]);
      if (i < n - 1) {
        chmin(ans, (x * b[i + 1]).a[0][1]);
      }
    }
  }
  output(ans);
}
