#include "template.hpp"

const int INF = 1 << 29;

constexpr int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> B(h);
    rep (i, h) cin >> B[i];

    int sx, sy, ax, ay, gx, gy;
    rep (i, h) {
        rep (j, w) {
            if (B[i][j] == 's') sx = i, sy = j, B[i][j] = '.';
            if (B[i][j] == 'a') ax = i, ay = j, B[i][j] = '.';
            if (B[i][j] == 'g') gx = i, gy = j, B[i][j] = '.';
        }
    }

    queue<tuple<int, int, int, int>> Q;
    vector D(h, vector(w, vector(h, vector(w, INF))));
    Q.emplace(sx, sy, ax, ay);
    D[sx][sy][ax][ay] = 0;
    while (!Q.empty()) {
        auto [sx, sy, ax, ay] = Q.front();
        Q.pop();
        rep (k, 4) {
            int sx2 = sx + dx[k], sy2 = sy + dy[k];
            int ax2 = ax, ay2 = ay;
            if (sx2 == ax and sy2 == ay) {
                ax2 += dx[k];
                ay2 += dy[k];
            }
            if (0 <= sx2 and sx2 < h and 0 <= sy2 and sy2 < w and B[sx2][sy2] != '#') {
                if (0 <= ax2 and ax2 < h and 0 <= ay2 and ay2 < w and B[ax2][ay2] != '#') {
                    if (chmin(D[sx2][sy2][ax2][ay2], D[sx][sy][ax][ay] + 1)) {
                        Q.emplace(sx2, sy2, ax2, ay2);
                    }
                }
            }
        }
    }

    int ans = INF;
    rep (x, h) {
        rep (y, w) {
            if (D[x][y][gx][gy] != -INF) chmin(ans, D[x][y][gx][gy]);
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;

    return 0;
}
