#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int nh = count(begin(s), end(s), 'H');
    int nq = count(begin(s), end(s), 'Q');

    if (nh > 0) {
        cout << -1 << endl;
        return 0;
    }

    // s は 'Q' をちょうど m^2 個含み, さらにある長さ n/m の文字列の m 回の繰り返しになっていないといけない
    int m = round(sqrt(nq));
    if (m * m != nq) {
        cout << -1 << endl;
        return 0;
    }
    if (m == 0 or n % m != 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i < m; i++) {
        if (s.substr(0, n / m) != s.substr(i * n / m, n / m)) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << s.substr(0, n / m) << endl;

    return 0;
}
