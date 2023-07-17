#include "template.hpp"

template<class T> struct edge {
    int to;
    T wt;
    edge(int to, const T& wt):to(to), wt(wt) {}
};
template<class T> using weighted_graph = vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
    G[v].emplace_back(u, wt);
}

int main() {
    int n; cin >> n;
    weighted_graph<int> T(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v; u--; v--;
        add_undirected_edge(T, u, v, i);
    }

    lint ans = 0;
    auto dfs = [&](auto&& dfs, int u, int p, int l, int r)->void {
        if (p == -1) {
            ans += lint(n) * (n - 1) / 2;
        }
        else {
            ans += lint(l + 1) * (n - r - 1);
        }
        for (const auto& e : T[u]) if (e.to != p) {
            dfs(dfs, e.to, u, min(l, e.wt), max(r, e.wt));
        }
    };
    dfs(dfs, 0, -1, n, 0);
    cout << ans << endl;

    return 0;
}
