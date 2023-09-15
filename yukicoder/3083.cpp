// super hard

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

bool is_leap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return y % 4 == 0;
}

int main() {
    int y, n, d;
    cin >> y >> n >> d;

    if (d > 333) {
        if (is_leap(y - 12)) d++;
        if (is_leap(y + 1)) d--;
    }
    int mn = n - min(d, n);
    int mx = min((is_leap(y - 12) ? 366 : 365) - d, n);
    cout << mn << " " << mx << endl;

    return 0;
}
