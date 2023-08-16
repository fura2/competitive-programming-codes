#include "template.hpp"

class union_find {
    int n;
    vector<int> p;

  public:
    union_find(int n = 0) { build(n); }
    void build(int n) {
        this->n = n;
        p.assign(n, -1);
    }
    int find(int u) { return p[u] < 0 ? u : p[u] = find(p[u]); }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (p[v] < p[u])
                swap(u, v);
            p[u] += p[v];
            p[v] = u;
            n--;
        }
    }
    bool is_same(int u, int v) { return find(u) == find(v); }
    int size() const { return n; }
    int size(int u) { return -p[find(u)]; }
};

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> E;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        E.emplace(u, v);
    }
    int q;
    cin >> q;
    vector<tuple<int, int, int>> Q(q);
    for (auto &[t, u, v] : Q) {
        cin >> t >> u >> v;
        u--;
        v--;
        if (t == 1)
            E.emplace(u, v);
        else if (t == 2)
            E.erase({u, v});
    }

    union_find U(n);
    for (auto [u, v] : E)
        U.unite(u, v);

    vector<string> ans(q);
    rrep(i, q) {
        auto [t, u, v] = Q[i];
        if (t == 1) {
            E.erase({u, v});
            U = union_find(n);
            for (auto [x, y] : E)
                U.unite(x, y);
        } else if (t == 2) {
            E.emplace(u, v);
            U.unite(u, v);
        } else {
            ans[i] = (U.is_same(u, v) ? "Yes" : "No");
        }
    }
    rep(i, q) cout << ans[i] << "\n";

    return 0;
}
