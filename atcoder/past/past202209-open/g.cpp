#include "template.hpp"

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<string> T(n);
    rep(i, n) cin >> T[i];

    int ans = 0;
    rep(S, 1 << l) if (__builtin_popcount(S) == l - k) {
        vector<string> T2(n);
        rep(i, n) rep(j, l) if (bit(S, j)) T2[i] += T[i][j];
        map<string, int> f;
        rep(i, n) {
            ++f[T2[i]];
        }
        for (auto [k, v] : f)
            chmax(ans, v);
    }
    cout << ans << endl;

    return 0;
}
