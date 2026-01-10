#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    double t0, s, d;
    cin >> t0 >> s >> d;

    // double t1 = t0 + d / s;
    // double ans = 0;
    // rep (i, 1000) {
    //     ans += max(min(t1, 30.0 + 24 * i) - max(t0, 18.0 + 24 * i), 0.0);
    // }
    // cout << setprecision(10) << ans << endl;

    cout << setprecision(10) << d / s << endl;

    return 0;
}
