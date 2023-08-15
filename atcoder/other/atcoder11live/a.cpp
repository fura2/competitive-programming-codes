#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define show(x) { std::cerr << #x << " = " << x << endl; }

using namespace std;

const int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

// unsigned int seed = random_device()();
unsigned int seed = 78;
mt19937 rng(seed);

int n, sx, sy;

int calc_score(vector<string> B) {
    bool vis[50][50][4] = {};
    int res = 0;
    int x = sx, y = sy, k = 0;
    while (!vis[x][y][k]) {
        vis[x][y][k] = true;
        int x2 = x + dx[k], y2 = y + dy[k];
        if (0 <= x2 && x2 < n && 0 <= y2 && y2 < n && B[x2][y2] == '.') {
            x = x2;
            y = y2;
            res++;
        }
        else {
            k = (k + 1) % 4;
        }
    }
    return res;
}

int main() {
    auto t_start = chrono::system_clock::now();

    show(seed);
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> sx >> sy;
    vector<string> B(n);
    rep(i, n) cin >> B[i];

    vector<pair<int, int>> ans;
    int score = calc_score(B);
    while (true) {
        auto t_now = chrono::system_clock::now();
        auto dt = chrono::duration_cast<chrono::milliseconds>(t_now - t_start).count();
        if (dt > 1950) break;

        int x0 = rng() % n;
        int y0 = rng() % n;
        if (B[x0][y0] == '#' || (x0 == sx && y0 == sy)) {
            continue;
        }

        B[x0][y0] = '#';
        int score_tmp = calc_score(B);
        if (score_tmp > score) {
            score = score_tmp;
            ans.emplace_back(x0, y0);
            continue;
        }
        B[x0][y0] = '.';
    }

    cout << ans.size() << endl;
    for (auto [x, y] : ans) cout << x << " " << y << endl;

    return 0;
}
