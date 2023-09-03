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
    union_find U(128);
    rep (i, n) {
        char a, b;
        cin >> a >> b;
        U.unite(a, b);
    }

    string s, t;
    cin >> s >> t;
    rep (i, int(s.size())) {
        if (not U.is_same(s[i], t[i])) {
            no();
            return 0;
        }
    }
    yes();

    return 0;
}
