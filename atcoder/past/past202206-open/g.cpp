#include "template.hpp"

class union_find {
    int n;
    vector<int> p;

  public:
    union_find(int n = 0) {
        build(n);
    }
    void build(int n) {
        this->n = n;
        p.assign(n, -1);
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
};

int main() {
    int n;
    cin >> n;
    union_find U(n);
    rep (n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        U.unite(u, v);
    }
    yesno(U.size() == 1);

    return 0;
}
