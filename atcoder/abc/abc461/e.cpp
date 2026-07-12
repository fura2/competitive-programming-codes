#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

struct MergeSortTree {
  int n;
  vector<vector<int>> data;

  MergeSortTree(const vector<int>& a) {
    n = bit_ceil(a.size());
    data.resize(2 * n);
    rep (i, a.size()) data[n + i] = {a[i]};
    rrep (i, 1, n) {
      vector<int>& L = data[2 * i];
      vector<int>& R = data[2 * i + 1];
      data[i].reserve(L.size() + R.size());
      int il = 0, ir = 0;
      while (il < L.size() || ir < R.size()) {
        if (il == L.size()) {
          data[i].push_back(R[ir++]);
        }
        else if (ir == R.size()) {
          data[i].push_back(L[il++]);
        }
        else {
          data[i].push_back(L[il] <= R[ir] ? L[il++] : R[ir++]);
        }
      }
    }
  }

  // [l, r) 内で x 以下の要素の個数を数える
  int query(int l, int r, int x) {
    int res = 0;
    auto f = [&](auto f, int a, int b, int u) -> void {
      if (b <= l) return;
      if (r <= a) return;
      if (l <= a && b <= r) {
        res += ranges::upper_bound(data[u], x) - data[u].begin();
        return;
      }
      int c = (a + b) / 2;
      f(f, a, c, 2 * u);
      f(f, c, b, 2 * u + 1);
    };
    f(f, 0, n, 1);
    return res;
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

  vector<int> R(q, INF), C(q, INF);
  vector pre(2, vector(n, -1));
  rep (i, q) {
    if (t[i] == 0) {
      R[i] = pre[t[i]][a[i]];
    }
    else {
      C[i] = pre[t[i]][a[i]];
    }
    pre[t[i]][a[i]] = i;
  }

  MergeSortTree Mr(R), Mc(C);
  lint ans = 0;
  rep (i, q) {
    if (t[i] == 0) {
      if (R[i] == -1)
        ans += n;
      else
        ans += Mc.query(R[i] + 1, i, R[i]);
    }
    else {
      ans -= Mr.query(C[i] + 1, i, C[i]);
    }
    output(ans);
  }
}
