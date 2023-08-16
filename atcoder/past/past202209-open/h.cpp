#include "template.hpp"

int main() {
    int n;
    lint x;
    cin >> n >> x;
    vector<lint> A(n), B(n), C(n);
    rep(i, n) cin >> A[i] >> B[i] >> C[i];

    vector<tuple<lint, lint, lint>> dp(x + 1, {-1, 0, 0});
    dp[0] = {0, 1e9, 0};
    rep(i, n) {
        rrep(w, B[i], x + 1) {
            auto [t0, t1, t2] = dp[w - B[i]];
            if (t0 != -1) {
                chmax(dp[w], {t0 + C[i], t1 - A[i], x - w});
            }
        }
    }

    auto [a0, a1, a2] = *max_element(all(dp));
    cout << a0 << " " << a1 << " " << a2 << endl;

    return 0;
}
