#include "template.hpp"

const lint INF = 1LL << 61;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> W(n);
    vector<lint> V(n);
    rep (i, n) cin >> W[i] >> V[i];

    vector dp(a + 1, vector(b + 1, -INF));
    vector dp_next(a + 1, vector(b + 1, -INF));
    dp[0][0] = 0;
    rep (i, n) {
        rep (wa, a + 1) {
            rep (wb, b + 1) {
                dp_next[wa][wb] = dp[wa][wb];
            }
        }
        rep (wa, a + 1) {
            rep (wb, b + 1) {
                if (dp[wa][wb] == -INF) continue;
                if (wa + W[i] <= a) chmax(dp_next[wa + W[i]][wb], dp[wa][wb] + V[i]);
                if (wb + W[i] <= b) chmax(dp_next[wa][wb + W[i]], dp[wa][wb] + V[i]);
            }
        }
        swap(dp, dp_next);
    }

    lint ans = -INF;
    rep (wa, a + 1) {
        rep (wb, b + 1) {
            chmax(ans, dp[wa][wb]);
        }
    }
    cout << ans << endl;

    return 0;
}
