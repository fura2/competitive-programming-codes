#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    int n;
    cin >> n;
    bool one = false;
    rep (i, n) {
        int v, w;
        cin >> v >> w;
        if (w == 1) one = true;
    }
    cout << (one ? "Yes" : "No") << endl;

    return 0;
}
