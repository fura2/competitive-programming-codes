#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n;
    string s; cin >> n >> s;

    rep(i, n) cout << s[i] << s[i];

    return 0;
}
