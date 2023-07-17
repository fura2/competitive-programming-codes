#include "template.hpp"

int main() {
    int n;
    string s; cin >> n >> s;

    int hist[10] = {};
    for (char c : s) hist[c - '0']++;

    lint ans = 0;
    rep(x, 10) rep(y, x + 1, 10) ans += llabs(x - y) * hist[x] * hist[y];
    cout << ans << endl;

    return 0;
}
