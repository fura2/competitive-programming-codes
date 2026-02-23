#include "template.hpp"

vector<int> f(int x, int y) {
    return { x, y, x - y, x + y };
}

int main() {
    int n; cin >> n;
    vector<bool> X(n, true), Y(n, true);
    vector<int> R(n - 1), C(n - 1);
    rep(i, n - 1) {
        cin >> R[i] >> C[i]; R[i]--; C[i]--;
        X[R[i]] = false;
        Y[C[i]] = false;
    }

    int ans[2];
    rep(i, n) if (X[i]) ans[0] = i;
    rep(i, n) if (Y[i]) ans[1] = i;
    rep(i, n - 1) {
        if (ans[0] - ans[1] == R[i] - C[i] || ans[0] + ans[1] == R[i] + C[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans[0] + 1 << " " << ans[1] + 1 << endl;

    return 0;
}
