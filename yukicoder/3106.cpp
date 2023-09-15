#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    int n;
    cin >> n;
    rep (i, n - 1) {
        int u, v;
        cin >> u >> v;
    }
    rep (i, n) {
        int a;
        cin >> a;
    }
    int q;
    cin >> q;
    rep (_, q) {
        int a, b, k, d;
        cin >> a >> b >> k >> d;
        cout << d << "\n";
    }

    return 0;
}
