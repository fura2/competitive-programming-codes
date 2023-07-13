#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define _overload4(a, b, c, d, e, ...) e
#define _overload5(a, b, c, d, e, f, ...) f
#define _overload6(a, b, c, d, e, f, g, ...) g

#define _rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define _rep3(i, a, b) _rep4(i, a, b, 1)
#define _rep2(i, n) _rep3(i, 0, n)
#define _rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) _overload4(__VA_ARGS__, _rep4, _rep3, _rep2, _rep1)(__VA_ARGS__)

#define _rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define _rrep3(i, a, b) _rrep4(i, a, b, 1)
#define _rrep2(i, n) _rrep3(i, 0, n)
#define rrep(...) _overload4(__VA_ARGS__, _rrep4, _rrep3, _rrep2)(__VA_ARGS__)

#define all(v) begin(v), end(v)

#define _show1(a) { std::clog << #a << " = " << a << endl; }
#define _show2(a, ...) { std::clog << #a << " = " << a << ", "; _show1(__VA_ARGS__); }
#define _show3(a, ...) { std::clog << #a << " = " << a << ", "; _show2(__VA_ARGS__); }
#define _show4(a, ...) { std::clog << #a << " = " << a << ", "; _show3(__VA_ARGS__); }
#define _show5(a, ...) { std::clog << #a << " = " << a << ", "; _show4(__VA_ARGS__); }
#define _show6(a, ...) { std::clog << #a << " = " << a << ", "; _show5(__VA_ARGS__); }
#define show(...) _overload6(__VA_ARGS__, _show6, _show5, _show4, _show3, _show2, _show1)(__VA_ARGS__)

using lint = long long;

template<typename T>
constexpr inline int bit(T x, unsigned int k) { return (x >> k) & 1; }

template<typename C>
long ssize(const C& c) { return std::size(c); }  // workaround until C++20

void yes() { std::cout << "Yes\n"; }
void no() { std::cout << "No\n"; }
void yesno(bool b) { std::cout << (b ? "Yes" : "No") << "\n"; }

template<class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e : v) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "]";
    return os;
}

struct Setup {
    Setup() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(11);
    }
} _setup;

using namespace std;

template<class capa_t, class cost_t>
class mcf_graph {
    struct edge {
        int to, rev;
        capa_t capa;
        cost_t cost;
        capa_t flow;
        edge(int to, int rev, const capa_t& capa, const cost_t& cost, const capa_t& flow):to(to), rev(rev), capa(capa), cost(cost), flow(flow) {}
    };

    vector<vector<edge>> G;

    static constexpr capa_t CAPA_INF = numeric_limits<capa_t>::max();
    static constexpr cost_t COST_INF = numeric_limits<cost_t>::max();

public:
    mcf_graph() {}
    mcf_graph(int n):G(n) {}

    void add_directed_edge(int u, int v, const capa_t& capa, const cost_t& cost) {
        G[u].emplace_back(v, G[v].size(), capa, cost, 0);
        G[v].emplace_back(u, G[u].size() - 1, 0, -cost, 0);
    }

    pair<capa_t, cost_t> minimum_cost_flow(int s, int t, capa_t limit = CAPA_INF) {
        int n = G.size();
        vector<int> pre(n);
        vector<cost_t> d(n), pot(n);
        priority_queue<pair<cost_t, int>> Q;

        auto augment = [&](bool first)->pair<capa_t, cost_t> {
            rep(u, n) d[u] = (u == s ? 0 : COST_INF);

            bool ok;
            if (first) {
                // Bellman-Ford
                rep(_, n) {
                    bool upd = false;
                    rep(u, n) if (d[u] < COST_INF) {
                        for (const edge& e : G[u]) if (e.capa - e.flow > 0) {
                            if (d[e.to] > d[u] + e.cost) {
                                d[e.to] = d[u] + e.cost;
                                pre[e.to] = e.rev;
                                upd = true;
                            }
                        }
                    }
                    if (!upd) break;
                }
                ok = (d[t] < COST_INF);
            }
            else {
                // Dijkstra
                ok = false;
                Q.emplace(0, s);
                while (!Q.empty()) {
                    int u;
                    cost_t tmp; tie(tmp, u) = Q.top(); Q.pop();

                    if (-tmp < d[u]) continue;
                    if (u == t) ok = true;

                    for (const edge& e : G[u]) if (e.capa - e.flow > 0) {
                        cost_t cost2 = d[u] + e.cost + pot[u] - pot[e.to];
                        if (d[e.to] > cost2) {
                            d[e.to] = cost2;
                            pre[e.to] = e.rev;
                            Q.emplace(-cost2, e.to);
                        }
                    }
                }
            }

            if (!ok) return { 0, 0 };

            capa_t water = limit;
            for (int u = t; u != s;) {
                edge& e1 = G[u][pre[u]];
                edge& e2 = G[e1.to][e1.rev];
                water = min(water, e2.capa - e2.flow);
                u = e1.to;
            }
            limit -= water;

            for (int u = t; u != s;) {
                edge& e1 = G[u][pre[u]];
                edge& e2 = G[e1.to][e1.rev];
                e1.flow -= water;
                e2.flow += water;
                u = e1.to;
            }

            rep(u, n) pot[u] += d[u];

            return { water, water * pot[t] };
        };

        capa_t res1 = 0;
        cost_t res2 = 0;
        for (bool first = true; limit > 0; first = false) {
            auto tmp = augment(first);
            if (tmp.first == 0) break;
            res1 += tmp.first;
            res2 += tmp.second;
        }
        return { res1, res2 };
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<lint> a(n), b(n), r(3);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, 3) cin >> r[i];

    mcf_graph<lint, lint> G(n + 5);
    int s = n + 3, t = n + 4;
    rep(u, 3) {
        G.add_directed_edge(s, u, m, 0);
    }
    rep(u, 3) rep(i, n) {
        int v = 3 + i;
        lint cost = a[i];
        rep(u + 1) cost *= b[i];
        G.add_directed_edge(u, v, 1, -(cost % r[u]));
    }
    rep(i, n) {
        int v = 3 + i;
        G.add_directed_edge(v, t, 1, a[i] * b[i]);
        G.add_directed_edge(v, t, 1, a[i] * b[i] * (b[i] - 1));
        G.add_directed_edge(v, t, 1, a[i] * b[i] * b[i] * (b[i] - 1));
    }
    cout << -G.minimum_cost_flow(s, t).second << endl;

    return 0;
}
