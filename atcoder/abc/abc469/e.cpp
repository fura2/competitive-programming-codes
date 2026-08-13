#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

template <class T>
class min_monoid {
  T a;

 public:
  min_monoid(const T& val = numeric_limits<T>::max()): a(val) {
  }
  min_monoid operator*(const min_monoid& x) const {
    return min(a, x.a);
  }
  T& get() {
    return a;
  }
  const T& get() const {
    return a;
  }
};

template <class M>
class segment_tree {
  int n, sz;
  vector<M> seg;

 public:
  segment_tree(int n = 0) {
    build(n);
  }
  template <class T>
  segment_tree(const vector<T>& a) {
    build(a);
  }

  void build(int n) {
    this->n = n;
    for (sz = 1; sz < n; sz <<= 1);
    seg.assign(2 * sz, M());
  }

  template <class T>
  void build(const vector<T>& a) {
    build(a.size());
    rep (i, a.size()) seg[sz + i] = a[i];
    for (int i = sz - 1; i > 0; i--) {
      seg[i] = seg[2 * i] * seg[2 * i + 1];
    }
  }

  const M& operator[](int i) const {
    return seg[sz + i];
  }

  void update(int i, const M& x) {
    i += sz;
    seg[i] = x;
    for (i >>= 1; i > 0; i >>= 1) seg[i] = seg[2 * i] * seg[2 * i + 1];
  }

  M product(int l, int r) const {
    M lcum, rcum;
    for (int a = l + sz, b = r + sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) lcum = lcum * seg[a++];
      if (b & 1) rcum = seg[--b] * rcum;
    }
    return lcum * rcum;
  }

  template <class N, class F>
  N operate(int l, int r, const F& f) {
    N lcum, rcum;
    for (int a = l + sz, b = r + sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) lcum = lcum * f(seg[a++]);
      if (b & 1) rcum = f(seg[--b]) * rcum;
    }
    return lcum * rcum;
  }

  template <class F>
  int max_right(int l, const F& f) const {
    if (l == n) return n;
    M cum;
    auto dfs = [&](auto&& dfs, int a, int b, int u) {
      if (a == b - 1) {
        cum = cum * seg[u];
        return f(cum) ? b : a;
      }

      int c = (a + b) / 2;
      if (c <= l) {
        return dfs(dfs, c, b, 2 * u + 1);
      }
      if (l <= a && f(cum * seg[u])) {
        cum = cum * seg[u];
        return b;
      }

      int idx = dfs(dfs, a, c, 2 * u);
      if (idx < c) return idx;
      return dfs(dfs, c, b, 2 * u + 1);
    };
    return min(dfs(dfs, 0, sz, 1), n);
  }

  template <class F>
  int min_left(int r, const F& f) const {
    if (r == 0) return 0;
    M cum;
    auto dfs = [&](auto&& dfs, int a, int b, int u) {
      if (a == b - 1) {
        cum = seg[u] * cum;
        return f(cum) ? a : b;
      }

      int c = (a + b) / 2;
      if (r <= c) {
        return dfs(dfs, a, c, 2 * u);
      }
      if (b <= r && f(seg[u] * cum)) {
        cum = seg[u] * cum;
        return a;
      }

      int idx = dfs(dfs, c, b, 2 * u + 1);
      if (idx > c) return idx;
      return dfs(dfs, a, c, 2 * u);
    };
    return dfs(dfs, 0, sz, 1);
  }
};

bool f(int n, int k, const string& s, double th) {
  vector<double> a(n);
  rep (i, n) {
    a[i] = (s[i] == 'o' ? 1 : 0) - th;
  }

  double sum = 0;
  int cnt = 0;
  segment_tree<min_monoid<double>> S(n + 1);
  S.update(0, 0.0);
  rep (i, n) {
    sum += a[i];
    if (s[i] == 'o') cnt++;
    S.update(cnt, S[cnt] * sum);
    if (cnt >= k) {
      if (sum - S.product(0, cnt - k + 1).get() > 0) return true;
    }
  }
  return false;
}

void testcase() {
  int n = input<int>();
  int k = input<int>();
  auto s = input<string>();

  double lo = 0, hi = 1;
  rep (_, 20) {
    double mi = (lo + hi) / 2;
    if (f(n, k, s, mi))
      lo = mi;
    else
      hi = mi;
  }
  output(hi);
}
