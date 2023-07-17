#include "template.hpp"

using graph = vector<vector<int>>;

void add_directed_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
}

bool is_DAG(const graph& G) {
    int n = G.size();
    vector<int> deg(n);
    rep(u, n) for (int v : G[u]) deg[v]++;

    int cnt = 0;
    queue<int> Q;
    rep(u, n) if (deg[u] == 0) Q.emplace(u);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        cnt++;
        for (int v : G[u]) if (--deg[v] == 0) Q.emplace(v);
    }
    return cnt == n;
}

int main() {
    int n, m; cin >> n >> m;
    graph G(n);
    rep(i, m) {
        int u, v; cin >> u >> v; u--; v--;
        add_directed_edge(G, u, v);
    }
    yesno(is_DAG(G));

    return 0;
}
