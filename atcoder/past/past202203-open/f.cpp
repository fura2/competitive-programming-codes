#include "template.hpp"

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector B(h, vector<int>(w));
    rep (i, h) {
        rep (j, w) cin >> B[i][j], B[i][j]--;
    }
    vector<int> C(n);
    rep (i, n) cin >> C[i], C[i]--;

    rep (i, h) {
        rep (j, w) {
            if (i + 1 < h and B[i][j] != B[i + 1][j] and C[B[i][j]] == C[B[i + 1][j]]) {
                no();
                return 0;
            }
            if (j + 1 < w and B[i][j] != B[i][j + 1] and C[B[i][j]] == C[B[i][j + 1]]) {
                no();
                return 0;
            }
        }
    }
    yes();

    return 0;
}
