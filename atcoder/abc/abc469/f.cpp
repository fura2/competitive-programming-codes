#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

class linear_sieve {
  vector<int> lpf, p;

 public:
  linear_sieve(int n): lpf(n + 1) {
    for (int i = 2; i <= n; i++) {
      if (lpf[i] == 0) {
        lpf[i] = i;
        p.emplace_back(i);
      }
      for (int j = 0; j < p.size() && p[j] <= lpf[i] && i * p[j] <= n; j++)
        lpf[i * p[j]] = p[j];
    }
  }

  const vector<int>& primes() const {
    return p;
  }

  bool is_prime(int a) const {
    assert(a <= (int)lpf.size() - 1);
    return a > 0 && lpf[a] == a;
  }

  map<int, int> prime_factorize(int a) const {
    assert(a <= (int)lpf.size() - 1);
    map<int, int> pf;
    for (; a > 1; a /= lpf[a]) ++pf[lpf[a]];
    return pf;
  }

  int number_of_divisors(int a) const {
    assert(a <= (int)lpf.size() - 1);
    int res = 1, cnt = 0, pre = -1;
    for (; a > 1; a /= lpf[a]) {
      if (pre == -1 || pre == lpf[a]) {
        cnt++;
      }
      else {
        res *= cnt + 1;
        cnt = 1;
      }
      pre = lpf[a];
    }
    return res * (cnt + 1);
  }
};

template <class T>
vector<T> divisors(const map<T, int>& pf) {
  vector<T> res = {T(1)};
  for (const auto& q: pf) {
    int m = res.size();
    T pp = 1;
    rep (i, q.second) {
      pp *= q.first;
      rep (i, m) res.emplace_back(res[i] * pp);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

class union_find {
  int n;
  vector<int> p;

 public:
  union_find(int n = 0) {
    build(n);
  }
  void build(int n) {
    this->n = n;
    p.assign(n, -1);
  }
  int find(int u) {
    return p[u] < 0 ? u : p[u] = find(p[u]);
  }
  void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
      if (p[v] < p[u]) swap(u, v);
      p[u] += p[v];
      p[v] = u;
      n--;
    }
  }
  bool is_same(int u, int v) {
    return find(u) == find(v);
  }
  int size() const {
    return n;
  }
  int size(int u) {
    return -p[find(u)];
  }
};

void testcase() {
  int n = input<int>();
  auto a = input<vector<int>>(n);

  int a_max = ranges::max(a);
  vector<vector<int>> idxs(a_max + 1);
  linear_sieve S(a_max);
  rep (u, n) {
    for (int d: divisors(S.prime_factorize(a[u]))) {
      idxs[d].emplace_back(u);
    }
  }

  lint ans = 0;
  union_find U(n);
  rrep (w, a_max + 1) {
    if (idxs[w].size() <= 1) continue;

    int u = U.find(idxs[w][0]);
    rep (i, 1, idxs[w].size()) {
      int v = U.find(idxs[w][i]);
      if (!U.is_same(u, v)) {
        // assert(gcd(a[u], a[v]) == w);
        U.unite(u, v);
        ans += w;
      }
    }
  }
  output(ans);
}
