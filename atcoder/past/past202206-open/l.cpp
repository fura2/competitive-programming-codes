#include "template.hpp"

int main() {
    string s, t;
    int r;
    cin >> s >> t >> r;

    int m = s.size(), n = t.size();

    vector dp(m + 1, vector(n + 1, vector(r + 1, -1)));
    dp[0][0][0] = 0;
    rep (i, m + 1) {
        rep (j, n + 1) {
            rep (k, r + 1) {
                if (dp[i][j][k] == -1) continue;
                if (i + 1 <= m) {
                    chmax(dp[i + 1][j][k], dp[i][j][k]);
                }
                if (j + 1 <= n) {
                    chmax(dp[i][j + 1][k], dp[i][j][k]);
                }
                if (i + 1 <= m and j + 1 <= n) {
                    chmax(dp[i + 1][j + 1][k], dp[i][j][k] + (s[i] == t[j] ? 1 : 0));
                    if (k + 1 <= r) {
                        chmax(dp[i + 1][j + 1][k + 1], dp[i][j][k] + 1);
                    }
                }
            }
        }
    }

    cout << *max_element(all(dp[m][n])) << endl;

    return 0;
}
