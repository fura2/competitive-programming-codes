#include "template.hpp"

int main() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> E;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (!(0 <= u && u < n && 0 <= v && v < n)) {
            no();
            return 0;
        }
        if (u > v)
            swap(u, v);
        if (u == v || E.count({u, v})) {
            no();
            return 0;
        }
        E.emplace(u, v);
    }
    yes();

    return 0;
}
