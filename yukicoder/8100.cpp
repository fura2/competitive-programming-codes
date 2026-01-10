#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt = n;
    rep (i, n) {
        int a;
        cin >> a;
        cnt -= a;
    }
    cout << (cnt + 1) % (n + 1) << "\n";
}

int main() {
    int t;
    cin >> t;
    rep (_, t) {
        solve();
    }
    return 0;
}
