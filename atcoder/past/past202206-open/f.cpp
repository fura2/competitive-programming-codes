#include "template.hpp"

int main() {
    int h, w;
    cin >> h >> w;
    vector B(w, vector<int>(h)); // (col, row)
    rep (i, h) {
        rep (j, w) {
            cin >> B[j][i];
        }
    }

    int n;
    cin >> n;
    rep (n) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        B[c][r] = 0;
        rep (j, w) stable_partition(all(B[c]), [](int x) { return x == 0; });
    }

    rep (i, h) {
        rep (j, w) {
            cout << B[j][i] << (j < w - 1 ? ' ' : '\n');
        }
    }

    return 0;
}
