#include "template.hpp"

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

int main() {
    int n, s, t; cin >> n >> s >> t; s--; t--;
    graph T(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v; u--; v--;
        add_undirected_edge(T, u, v);
    }

    vector<int> P = { s };
    auto dfs1 = [&](auto&& dfs, int u, int p) {
        if (u == t) {
            return true;
        }
        for (int v : T[u]) if (v != p) {
            if (dfs(dfs, v, u)) {
                P.emplace_back(v);
                return true;
            }
        }
        return false;
    };
    dfs1(dfs1, s, -1);

    vector<int> d(n, -1);
    queue<int> Q;
    for (int u : P) {
        d[u] = 0;
        Q.emplace(u);
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : T[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                Q.emplace(v);
            }
        }
    }

    rep(u, n) cout << d[u] + 1 << "\n";

    return 0;
}
