#include "template.hpp"

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    set<int> S;
    rep(i, n) rep(j, i + 1, n) rep(k, j + 1, n) S.emplace(a[i] * a[j] * a[k]);
    cout << S.size() << endl;

    return 0;
}
