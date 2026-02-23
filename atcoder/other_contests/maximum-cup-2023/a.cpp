#include "template.hpp"

int main() {
    int n;
    cin >> n;

    map<lint, lint> H;
    rep (i, n) {
        lint a;
        cin >> a;
        ++H[a];
    }

    lint ans = 0;
    for (auto [v, c] : H) ans += c * (c - 1) / 2;
    cout << ans << endl;

    return 0;
}
