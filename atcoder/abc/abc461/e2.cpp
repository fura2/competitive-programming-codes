#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

template <class G>
class FenwickTree {
  vector<G> a;

 public:
  FenwickTree(int n = 0) {
    build(n);
  }
  FenwickTree(const vector<G>& a) {
    build(a);
  }
  void build(int n) {
    a.assign(n, G{});
  }
  void build(const vector<G>& a) {
    this->a = a;
    for (int i = 1; i <= a.size(); i++)
      if (i + (i & -i) <= a.size())
        (this->a)[i + (i & -i) - 1] += (this->a)[i - 1];
  }
  void add(int i, const G& val) {
    for (i++; i <= a.size(); i += i & -i) a[i - 1] += val;
  }
  G sum(int l, int r) const {
    if (l == 0) {
      G res{};
      for (; r > 0; r -= r & -r) res += a[r - 1];
      return res;
    }
    return sum(0, r) - sum(0, l);
  }
  int lower_bound(G val) const {
    if (!(G{} < val)) return 0;
    int x = 0, k;
    for (k = 1; k <= a.size(); k <<= 1);
    for (k >>= 1; k > 0; k >>= 1)
      if (x + k <= a.size() && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
    return x;
  }
  int upper_bound(G val) const {
    if (val < G{}) return 0;
    int x = 0, k;
    for (k = 1; k <= a.size(); k <<= 1);
    for (k >>= 1; k > 0; k >>= 1)
      if (x + k <= a.size() && !(val < a[x + k - 1]))
        val -= a[x + k - 1], x += k;
    return x;
  }
};

void testcase() {
  int n = input<int>();
  int q = input<int>();
  vector<int> t(q), a(q);
  rep (i, q) {
    t[i] = input<int>() - 1;
    a[i] = input<int>() - 1;
  }

  vector pre(2, vector(n, -1));
  FenwickTree<int> Fr(q), Fc(q);
  lint ans = 0;
  rep (i, q) {
    int j = pre[t[i]][a[i]];
    if (t[i] == 0) {
      if (j == -1) {
        ans += n;
      }
      else {
        ans += Fc.sum(j + 1, i);
        Fr.add(j, -1);
      }
      Fr.add(i, 1);
    }
    else {
      if (j != -1) {
        Fc.add(j, -1);
      }
      ans -= Fr.sum(j + 1, i);
      Fc.add(i, 1);
    }
    output(ans);
    pre[t[i]][a[i]] = i;
  }
}
