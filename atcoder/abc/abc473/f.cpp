#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

struct AdditionMonoid {
  lint x;
  AdditionMonoid(): x{} {
  }
  AdditionMonoid(lint x): x{x} {
  }
  AdditionMonoid& operator*=(const AdditionMonoid& m) {
    x += m.x;
    return *this;
  }
  AdditionMonoid operator*(const AdditionMonoid& m) const {
    return AdditionMonoid{*this} *= m;
  }
  bool operator==(const AdditionMonoid& m) const {
    return x == m.x;
  }
};

struct MinMonoid {
  lint x;
  MinMonoid(): x{LINF} {
  }
  MinMonoid(lint x): x{x} {
  }
  MinMonoid& operator*=(const MinMonoid& m) {
    if (x > m.x) x = m.x;
    return *this;
  }
  MinMonoid operator*(const MinMonoid& m) const {
    return MinMonoid{*this} *= m;
  }
  bool operator==(const MinMonoid& m) const {
    return x == m.x;
  }
};

MinMonoid action(const MinMonoid& x, const AdditionMonoid& m) {
  return {x.x + m.x};
}

template <typename X, typename M, auto f>
class LazySegmentTree {
 public:
  LazySegmentTree(int n): e{}, id{} {
    this->n = bit_ceil<unsigned int>(n);
    x.assign(2 * this->n, e);
    m.assign(2 * this->n, id);
  }

  LazySegmentTree(int n, const X& v): e{}, id{} {
    this->n = bit_ceil<unsigned int>(n);
    x.assign(2 * this->n, e);
    m.assign(2 * this->n, id);
    rep (i, v.size()) x[n + i] = v;
    for (int i = n - 1; i >= 1; i--) x[i] = x[2 * i] * x[2 * i + 1];
  }

  LazySegmentTree(const vector<X>& v): e{}, id{} {
    this->n = bit_ceil(v.size());
    x.assign(2 * this->n, e);
    m.assign(2 * this->n, id);
    rep (i, v.size()) x[n + i] = v[i];
    for (int i = n - 1; i >= 1; i--) x[i] = x[2 * i] * x[2 * i + 1];
  }

  void apply(int l, int r, const M& m) {
    apply(1, 0, n, l, r, m);
  }

  X product(int l, int r) {
    return product(1, 0, n, l, r);
  }

  X product() const {
    return x[1];
  }

 private:
  int n;
  vector<X> x;
  vector<M> m;
  const X e;
  const M id;

  // 不変条件: この関数の実行後はつねに m[u] == id
  void apply(int u, int a, int b, int l, int r, const M& m_) {
    propagate(u);
    if (b <= l || r <= a) return;
    if (l <= a && b <= r) {
      m[u] = m_;
      propagate(u);
      return;
    }
    int c = (a + b) / 2;
    apply(2 * u, a, c, l, r, m_);
    apply(2 * u + 1, c, b, l, r, m_);
    x[u] = x[2 * u] * x[2 * u + 1];
  }

  X product(int u, int a, int b, int l, int r) {
    propagate(u);
    if (b <= l || r <= a) return e;
    if (l <= a && b <= r) return x[u];
    int c = (a + b) / 2;
    return product(2 * u, a, c, l, r) * product(2 * u + 1, c, b, l, r);
  }

  void propagate(int u) {
    if (m[u] == id) return;
    x[u] = f(x[u], m[u]);
    if (u < n) {
      m[2 * u] *= m[u];
      m[2 * u + 1] *= m[u];
    }
    m[u] = id;
  }
};

void testcase() {
  auto n = input<int>();
  auto s = input<string>();
  auto q = input<int>();

  vector<int> a(n + 1);
  rep (i, n) {
    a[i + 1] = a[i] + (s[i] == 'A' ? 1 : -1);
  }
  vector<MinMonoid> init(n + 1);
  rep (i, n + 1) init[i] = a[i];

  LazySegmentTree<MinMonoid, AdditionMonoid, action> S{init};

  rep (_, q) {
    auto type = input<int>();
    if (type == 1) {
      auto i = input<int>() - 1;
      auto c = input<char>();
      if (s[i] == c) continue;
      if (c == 'A') {
        S.apply(i + 1, n + 1, 2);
      }
      else {
        S.apply(i + 1, n + 1, -2);
      }
      s[i] = c;
    }
    else {
      auto l = input<int>() - 1, r = input<int>();
      yesno(S.product(l, l + 1).x <= S.product(l + 1, r + 1).x);
    }
  }
}
