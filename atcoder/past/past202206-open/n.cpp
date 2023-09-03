#include "template.hpp"

const lint INF = 1LL << 61;

const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    int h, w;
    cin >> h >> w;
    vector C(h, vector<lint>(w));
    rep (i, h) {
        rep (j, w) {
            cin >> C[i][j];
        }
    }
    C[0][0] = C[h - 1][w - 1] = INF;

    vector D(h, vector(w, INF));
    vector pre(h, vector<pair<int, int>>(w, {-1, -1}));
    priority_queue<tuple<lint, int, int>> Q;
    rep (i, h) {
        rep (j, w) {
            if ((i == 0 and j > 0) or (j == w - 1 and i < h - 1)) {
                D[i][j] = C[i][j];
                Q.emplace(-D[i][j], i, j);
            }
        }
    }
    while (not Q.empty()) {
        auto [md, i, j] = Q.top();
        Q.pop();
        if (-md > D[i][j]) continue;
        rep (k, 8) {
            int x = i + dx[k], y = j + dy[k];
            if (0 <= x and x < h and 0 <= y and y < w) {
                if (chmin(D[x][y], D[i][j] + C[x][y])) {
                    pre[x][y] = {i, j};
                    Q.emplace(-D[x][y], x, y);
                }
            }
        }
    }

    lint d_min = INF;
    int i_min = -1, j_min;
    rep (i, h) {
        rep (j, w) {
            if ((i == h - 1 and j < w - 1) or (j == 0 and i > 0)) {
                if (chmin(d_min, D[i][j])) {
                    i_min = i;
                    j_min = j;
                }
            }
        }
    }
    vector ans(h, string(w, '.'));
    while (i_min != -1) {
        ans[i_min][j_min] = '#';
        tie(i_min, j_min) = pre[i_min][j_min];
    }
    cout << d_min << endl;
    rep (i, h) cout << ans[i] << "\n";

    return 0;
}
