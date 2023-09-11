#include "template.hpp"

template<class T>
struct edge {
    int to;
    T wt;
    edge(int to, const T& wt): to(to), wt(wt) {}
};
template<class T>
using weighted_graph = vector<vector<edge<T>>>;

template<class T>
void add_directed_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G, int s) {
    constexpr T INF = numeric_limits<T>::max();

    int n = G.size();
    vector<T> d(n, INF);
    d[s] = T{};
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> Q;
    Q.emplace(T{}, s);
    while (!Q.empty()) {
        T d0;
        int u;
        tie(d0, u) = Q.top();
        Q.pop();
        if (d0 > d[u]) continue;
        for (const auto& [v, wt]: G[u]) {
            if (d[v] > d[u] + wt) {
                d[v] = d[u] + wt;
                Q.emplace(d[v], v);
            }
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;
    weighted_graph<lint> G(n), H(n);
    rep (i, m) {
        int u, v;
        lint w;
        cin >> u >> v >> w;
        u--;
        v--;
        add_directed_edge(G, u, v, w);
        add_directed_edge(H, v, u, w);
    }

    auto d1 = Dijkstra(G, 0);
    auto d2 = Dijkstra(H, n - 1);

    rep (u, n) {
        if (d1[u] == LONG_MAX or d2[u] == LONG_MAX) {
            cout << -1 << "\n";
        }
        else {
            cout << d1[u] + d2[u] << "\n";
        }
    }

    return 0;
}
