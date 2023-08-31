#include "template.hpp"

int square_free(int v) {
    for (int a = 2; a * a <= v; a++) {
        if (v % (a * a) == 0) {
            v /= a * a;
            a--;
        }
    }
    return v;
}

int main() {
    int n;
    cin >> n;

    vector<int> ans(n);
    vector<bool> used(n + 1);
    rep (i, n) {
        int p = square_free(i + 1);
        int v = sqrt(n / p); // maximum v s.t. p * v^2 <= n
        while (true) {
            if (not used[v * v * p]) {
                used[v * v * p] = true;
                ans[i] = v * v * p;
                break;
            }
            v--;
        }
    }
    rep (i, n) cout << ans[i] << (i < n - 1 ? ' ' : '\n');

    return 0;
}
