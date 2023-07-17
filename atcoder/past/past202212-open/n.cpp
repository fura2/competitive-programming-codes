#include "template.hpp"

int main() {
    int n; cin >> n;
    vector<lint> A(n);
    rep(i, n) cin >> A[i];
    int q; cin >> q;
    vector<tuple<int, int, int>> Q(q);
    rep(i, q) {
        int l, r; cin >> l >> r; l--;
        Q[i] = { i, l, r };
    }

    // Mo's algorithm
    int b = n / min<int>(n, sqrt(q)); // size of each block
    sort(all(Q), [&](const auto& x, const auto& y) {
        const auto& [_1, l1, r1] = x;
        const auto& [_2, l2, r2] = y;
        int i1 = l1 / b, i2 = l2 / b;
        if (i1 != i2) return i1 < i2;
        return i1 % 2 == 0 ? r1 < r2 : r1 > r2;
    });

    const lint mx = 1e9 + 1;
    lint res = mx * mx;
    multiset<lint> S = { 0LL, mx }; // sentinels
    auto push = [&](int& x) {
        auto it = S.lower_bound(A[x]);
        lint al = *prev(it), ar = *it;
        res -= (ar - al) * (ar - al);
        res += (ar - A[x]) * (ar - A[x]) + (A[x] - al) * (A[x] - al);
        S.emplace(A[x]);
    };
    auto pop = [&](int& x) {
        S.erase(S.find(A[x]));
        auto it = S.lower_bound(A[x]);
        lint al = *prev(it), ar = *it;
        res -= (ar - A[x]) * (ar - A[x]) + (A[x] - al) * (A[x] - al);
        res += (ar - al) * (ar - al);
    };

    vector<lint> ans(q);
    int l = 0, r = 0;
    for (const auto& [qi, ql, qr] : Q) {
        while (l > ql) { l--; push(l); }
        while (r < qr) { push(r); r++; }
        while (l < ql) { pop(l); l++; }
        while (r > qr) { r--; pop(r); }
        ans[qi] = res;
        // remove contribution from sentinels
        lint a0 = *next(S.begin());
        lint a1 = *prev(S.end(), 2);
        ans[qi] -= a0 * a0 + (mx - a1) * (mx - a1);
    }

    rep(i, q) cout << ans[i] << "\n";

    return 0;
}
