#include "template.hpp"

void solve() {
    int n, a, m;
    cin >> n >> a >> m;
    a %= m;

    vector<int> O;
    int x = a;
    do {
        O.emplace_back(x);
        x = (x + a) % m;
    } while (x != a);

    vector<lint> cnt(m);
    rep(i, size(O)) {
        cnt[O[i]] = n / size(O);
        if (i < n % size(O))
            cnt[O[i]]++;
    }

    lint ans = 0;
    rep(i, 1, m) {
        ans += (m - i) * cnt[i];
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(t) solve();
    return 0;
}
