#include "template.hpp"

int main() {
    int n; cin >> n;
    vector<lint> a(n);
    rep(i, n) cin >> a[i];

    vector<lint> dp(n + 1);
    rep(i, n) dp[i + 1] = max(dp[i] + a[i], a[i]);
    cout << *max_element(dp.begin() + 1, dp.end()) << endl;

    return 0;
}
