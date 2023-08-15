#include "template.hpp"

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    vector<vector<int>> I(200001);
    rep(i, n) {
        int k;
        cin >> k;
        rep(k) {
            int x;
            cin >> x;
            I[x].emplace_back(i);
        }
    }

    int q;
    cin >> q;
    vector<bool> ok(n);
    rep(q) {
        fill(all(ok), true);
        int k;
        cin >> k;
        rep(k) {
            int x;
            cin >> x;
            for (int i : I[x])
                ok[i] = false;
        }
        int i_max = -1;
        rep(i, n) if (ok[i]) {
            if (i_max == -1 || A[i_max] < A[i]) {
                i_max = i;
            }
        }
        cout << (i_max == -1 ? -1 : i_max + 1) << "\n";
    }

    return 0;
}
