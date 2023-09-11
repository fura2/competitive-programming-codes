#include "template.hpp"

class union_find {
    int n;
    vector<int> p;
    vector<vector<int>> C;

  public:
    union_find(int n): n(n), p(n, -1), C(n) {
        rep (u, n) C[u].emplace_back(u);
    }
    int find(int u) {
        return p[u] < 0 ? u : p[u] = find(p[u]);
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (p[v] < p[u]) swap(u, v);
            p[u] += p[v];
            p[v] = u;
            n--;
            C[u].insert(C[u].end(), C[v].begin(), C[v].end());
            C[v].clear();
        }
    }
    bool is_same(int u, int v) {
        return find(u) == find(v);
    }
    int size() const {
        return n;
    }
    int size(int u) {
        return -p[find(u)];
    }
    vector<int> connected_component(int u) {
        return C[find(u)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    union_find U(n);
    rep (q) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            U.unite(u, v);
        }
        else {
            int u;
            cin >> u;
            u--;
            auto C = U.connected_component(u);
            sort(all(C));
            for (int u: C) cout << u + 1 << " ";
            cout << "\n";
        }
    }
    return 0;
}
