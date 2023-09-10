#include "template.hpp"

constexpr int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

int main() {
    int h, w, x0, y0;
    cin >> h >> w >> x0 >> y0;
    x0--;
    y0--;
    vector A(h, vector<lint>(w));
    rep (i, h) {
        rep (j, w) cin >> A[i][j];
    }

    lint p = A[x0][y0];
    A[x0][y0] = 0;

    priority_queue<tuple<lint, int, int>> Q;
    Q.emplace(0, x0, y0);
    while (not Q.empty()) {
        auto [_, x, y] = Q.top();
        Q.pop();

        if (A[x][y] == -1 or p <= A[x][y]) continue;
        p += A[x][y];
        A[x][y] = -1;

        rep (k, 4) {
            int x2 = x + dx[k], y2 = y + dy[k];
            if (0 <= x2 and x2 < h and 0 <= y2 and y2 < w and A[x2][y2] != -1) {
                Q.emplace(-A[x2][y2], x2, y2);
            }
        }
    }

    bool ok = true;
    rep (i, h) {
        rep (j, w) {
            if (A[i][j] != -1) ok = false;
        }
    }
    yesno(ok);

    return 0;
}
