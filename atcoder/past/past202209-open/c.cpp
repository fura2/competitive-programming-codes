#include "template.hpp"

int main() {
    int P[3][6];
    rep(i, 3) rep(j, 6) cin >> P[i][j];

    double ans[19] = {};
    rep(i, 6) rep(j, 6) rep(k, 6) {
        ans[i + j + k + 3] += P[0][i] * P[1][j] * P[2][k] / 1e6;
    }
    rep(i, 18) cout << ans[i + 1] << endl;

    return 0;
}
