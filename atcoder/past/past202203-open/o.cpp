#include "template.hpp"

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

vector<vector<int>> connected_components(const graph& G) {
    int n = G.size();
    vector<vector<int>> res;
    vector<bool> vis(n);
    rep (u, n)
        if (!vis[u]) {
            vis[u] = true;
            res.emplace_back();
            queue<int> Q;
            Q.emplace(u);
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                res.back().emplace_back(v);
                for (int w: G[v])
                    if (!vis[w]) {
                        vis[w] = true;
                        Q.emplace(w);
                    }
            }
        }
    return res;
}

// two coloring of the connected component which contains s
pair<bool, vector<int>> two_coloring_at(const graph& G, int s) {
    int n = G.size();
    vector<int> color(n, -1);
    color[s] = 0;
    queue<int> Q;
    Q.emplace(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w: G[v]) {
            if (color[w] == -1) {
                color[w] = 1 - color[v];
                Q.emplace(w);
            }
            else if (color[w] == color[v])
                return {false, vector<int>()};
        }
    }
    return {true, color};
}

int main() {
    int n, m;
    cin >> n >> m;
    graph G(n);
    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        add_undirected_edge(G, u, v);
    }

    int n1 = 0, n2 = 0;
    rep (i, n) {
        if ((i + 1) % 3 == 1) n1++;
        if ((i + 1) % 3 == 2) n2++;
    }
    auto CC = connected_components(G);

    // dp[x1][x2] = ((n1, n2) = (x1, x2) が作れるかどうか)
    vector dp(n1 + 1, vector(n2 + 1, false));
    dp[0][0] = true;
    rep (i, ssize(CC)) {
        const auto& C = CC[i];
        auto [b, color] = two_coloring_at(G, C[0]);

        if (not b) { // C は 0 として使うしかない
            continue;
        }

        // C を (1, 2) or (2, 1) として使っても 0 として使ってもいい
        int nl = count(all(color), 0);
        int nr = count(all(color), 1);
        rrep (x1, n1 + 1) {
            rrep (x2, n2 + 1) {
                if (not dp[x1][x2]) continue;
                if (x1 + nl <= n1 and x2 + nr <= n2) dp[x1 + nl][x2 + nr] = true;
                if (x1 + nr <= n1 and x2 + nl <= n2) dp[x1 + nr][x2 + nl] = true;
            }
        }
    }
    yesno(dp[n1][n2]);

    return 0;
}
