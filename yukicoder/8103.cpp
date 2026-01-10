#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using lint = long long;

int main() {
    int n;
    cin >> n;
    vector<lint> A(n);
    rep (i, n) cin >> A[i];

    lint mx = *max_element(begin(A), end(A));

    lint ans = 0;
    rep (i, n) {
        ans += max(abs(mx), abs(A[i]));
    }
    cout << ans << endl;

    return 0;
}
