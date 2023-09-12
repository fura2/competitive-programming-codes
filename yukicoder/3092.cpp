#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    rep (i, m) {
        int p, q, a, b;
        cin >> p >> q >> a >> b;
        if (a < 0 or b < 0) {
            cout << "-1" << endl;
            return 0;
        }
    }
    rep (i, n) cout << "1" << (i < n - 1 ? " " : "\n");

    return 0;
}
