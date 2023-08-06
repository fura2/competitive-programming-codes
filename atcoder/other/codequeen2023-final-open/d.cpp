#include "template.hpp"

lint h, w;

// (sx ,sy) から (tx, ty) へちょうど二手で移動する方法の数
lint f(lint sx, lint sy, lint tx, lint ty) {
    lint res = 0;

    // 縦移動
    {
        if (sy == ty) {
            res += (sx == tx ? h - 1 : h - 2);
        }
        else {
            lint x;
            set<lint> X;
            X.emplace(tx);
            x = tx - ty + sy; if (0 <= x && x < h) X.emplace(x);
            x = tx + ty - sy; if (0 <= x && x < h) X.emplace(x);
            X.erase(sx);
            res += X.size();
        }
    }

    // 横移動
    {
        if (sx == tx) {
            res += (sy == ty ? w - 1 : w - 2);
        }
        else {
            lint y;
            set<lint> Y;
            Y.emplace(ty);
            y = ty - tx + sx; if (0 <= y && y < w) Y.emplace(y);
            y = ty + tx - sx; if (0 <= y && y < w) Y.emplace(y);
            Y.erase(sy);
            res += Y.size();
        }
    }

    // 斜め移動 ／
    {
        lint len;
        if (sx + sy < min(h, w)) len = sx + sy + 1;
        else if (sx + sy < max(h, w)) len = min(h, w);
        else len = min(h, w) - ((sx + sy) - max(h, w) + 1);

        if (sx + sy == tx + ty) {
            res += (sx == tx ? len - 1 : len - 2);
        }
        else {
            lint x, y;
            set<pair<lint, lint>> XY;
            if ((sx + sy) % 2 == (tx + ty) % 2) {
                x = tx + ((sx + sy) - (tx + ty)) / 2;
                y = ty + ((sx + sy) - (tx + ty)) / 2;
                if (0 <= x && x < h && 0 <= y && y < w) XY.emplace(x, y);
            }
            x = tx; y = sy + sx - tx;
            if (0 <= x && x < h && 0 <= y && y < w) XY.emplace(x, y);
            x = sx + sy - ty; y = ty;
            if (0 <= x && x < h && 0 <= y && y < w) XY.emplace(x, y);
            XY.erase({ sx, sy });
            res += XY.size();
        }
    }

    // 斜め移動 ＼
    {
        lint len;
        if (sx - sy < -w + min(h, w)) len = w + sx - sy;
        else if (sx - sy <= -w + max(h, w)) len = min(h, w);
        else len = min(h, w) - ((sx - sy) - (max(h, w) - w));

        if (sx - sy == tx - ty) {
            res += (sx == tx ? len - 1 : len - 2);
        }
        else {
            lint x, y;
            set<pair<lint, lint>> XY;
            if ((sx + sy) % 2 == (tx + ty) % 2) {
                x = tx + ((sx - sy) - (tx - ty)) / 2;
                y = ty - ((sx - sy) - (tx - ty)) / 2;
                if (0 <= x && x < h && 0 <= y && y < w) XY.emplace(x, y);
            }
            x = tx; y = sy + tx - sx;
            if (0 <= x && x < h && 0 <= y && y < w) XY.emplace(x, y);
            x = sx + ty - sy; y = ty;
            if (0 <= x && x < h && 0 <= y && y < w) XY.emplace(x, y);
            XY.erase({ sx, sy });
            res += XY.size();
        }
    }

    return res;
}

int main() {
    lint sx, sy, tx, ty; cin >> h >> w >> sx >> sy >> tx >> ty; sx--; sy--; tx--; ty--;

    lint ans = 0;
    rep(x, h) if (x != sx) ans += f(x, sy, tx, ty);
    rep(y, w) if (y != sy) ans += f(sx, y, tx, ty);
    rep(d, -max(h, w), max(h, w) + 1) if (d != 0) {
        lint x, y;
        x = sx + d, y = sy + d;
        if (0 <= x && x < h && 0 <= y && y < w) ans += f(x, y, tx, ty);
        x = sx + d; y = sy - d;
        if (0 <= x && x < h && 0 <= y && y < w) ans += f(x, y, tx, ty);
    }
    cout << ans << endl;

    return 0;
}
