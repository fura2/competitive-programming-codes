#include "template.hpp"

int main() {
    int h, w, sx, sy, tx, ty;
    cin >> h >> w >> sx >> sy >> tx >> ty; sx--; sy--; tx--; ty--;

    // 一手で行けるマスを列挙
    auto f = [&](int sx, int sy) {
        vector<pair<int, int>> S;
        rep(x, h) if (x != sx) S.emplace_back(x, sy);
        rep(y, w) if (y != sy) S.emplace_back(sx, y);
        rep(d, -max(h, w), max(h, w) + 1) if (d != 0) {
            lint x, y;
            x = sx + d, y = sy + d;
            if (0 <= x && x < h && 0 <= y && y < w) S.emplace_back(x, y);
            x = sx + d; y = sy - d;
            if (0 <= x && x < h && 0 <= y && y < w) S.emplace_back(x, y);
        }
        return S;
    };

    auto S = f(sx, sy);
    auto T = f(tx, ty);
    sort(all(T));

    lint ans = 0;
    map<int, lint> S2[4], T2[4]; // direction -> histogram
    for (auto [x, y] : S) {
        ++S2[0][x];
        ++S2[1][y];
        ++S2[2][x + y];
        ++S2[3][x - y];
    }
    for (auto [x, y] : T) {
        ++T2[0][x];
        ++T2[1][y];
        ++T2[2][x + y];
        ++T2[3][x - y];
    }
    rep(i, h) ans += S2[0][i] * T2[0][i];
    rep(j, w) ans += S2[1][j] * T2[1][j];
    rep(d, h + w) ans += S2[2][d] * T2[2][d];
    rep(d, -max(h, w), max(h, w) + 1) ans += S2[3][d] * T2[3][d];

    // 二手で行けるケースも数えたので引く
    for (auto [x, y] : S) if (binary_search(all(T), make_pair(x, y))) ans -= 4;

    cout << ans << endl;

    return 0;
}
