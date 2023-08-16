#include "template.hpp"

template <class M>
class segment_tree {
    int n, sz;
    vector<M> seg;

  public:
    segment_tree(int n = 0) { build(n); }
    template <class T>
    segment_tree(const vector<T> &a) { build(a); }

    void build(int n) {
        this->n = n;
        for (sz = 1; sz < n; sz <<= 1)
            ;
        seg.assign(2 * sz, M());
    }

    template <class T>
    void build(const vector<T> &a) {
        build(a.size());
        rep(i, a.size()) seg[sz + i] = a[i];
        for (int i = sz - 1; i > 0; i--) {
            seg[i] = seg[2 * i] * seg[2 * i + 1];
        }
    }

    const M &operator[](int i) const {
        return seg[sz + i];
    }

    void update(int i, const M &x) {
        i += sz;
        seg[i] = x;
        for (i >>= 1; i > 0; i >>= 1)
            seg[i] = seg[2 * i] * seg[2 * i + 1];
    }

    M product(int l, int r) const {
        M lcum, rcum;
        for (int a = l + sz, b = r + sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1)
                lcum = lcum * seg[a++];
            if (b & 1)
                rcum = seg[--b] * rcum;
        }
        return lcum * rcum;
    }

    template <class N, class F>
    N operate(int l, int r, const F &f) {
        N lcum, rcum;
        for (int a = l + sz, b = r + sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1)
                lcum = lcum * f(seg[a++]);
            if (b & 1)
                rcum = f(seg[--b]) * rcum;
        }
        return lcum * rcum;
    }

    template <class F>
    int max_right(int l, const F &f) const {
        if (l == n)
            return n;
        M cum;
        auto dfs = [&](auto &&dfs, int a, int b, int u) {
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
            if (idx < c)
                return idx;
            return dfs(dfs, c, b, 2 * u + 1);
        };
        return min(dfs(dfs, 0, sz, 1), n);
    }

    template <class F>
    int min_left(int r, const F &f) const {
        if (r == 0)
            return 0;
        M cum;
        auto dfs = [&](auto &&dfs, int a, int b, int u) {
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
            if (idx > c)
                return idx;
            return dfs(dfs, a, c, 2 * u);
        };
        return dfs(dfs, 0, sz, 1);
    }
};

template <class T>
class min_monoid {
    T a;

  public:
    min_monoid(const T &val = numeric_limits<T>::max()) : a(val) {}
    min_monoid operator*(const min_monoid &x) const {
        return min(a, x.a);
    }
    T &get() { return a; }
    const T &get() const { return a; }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, lint>> I;
    rep(i, n) {
        lint a;
        cin >> a;
        I.emplace_back(i, i + 1, a);
    }
    rep(i, m) {
        lint b;
        int l, r;
        cin >> b >> l >> r;
        l--;
        I.emplace_back(l, r, b);
    }

    vector<vector<pair<int, lint>>> r2lc(n + 1);
    for (auto [l, r, cost] : I) {
        r2lc[r].emplace_back(l, cost);
    }

    segment_tree<min_monoid<lint>> dp(n + 1);
    dp.update(0, 0);
    rep(r, 1, n + 1) {
        for (auto [l, cost] : r2lc[r]) {
            lint val = dp.product(l, r).get() + cost;
            if (val < dp[r].get())
                dp.update(r, val);
        }
    }
    cout << dp[n].get() << endl;

    return 0;
}
