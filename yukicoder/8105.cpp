// すべての入力は素数なので, 素数列に含まれる等差数列を調べる.
// https://en.wikipedia.org/wiki/Primes_in_arithmetic_progression#Minimal_primes_in_AP
// を見ると, N も素数であることから, A_{N-1} <= 10^9 を満たすためには
// 公差 = 0 または N <= 13 でないといけないことが分かる.

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using lint = long long;

const lint INF = 1LL << 61;

lint modpow(lint a, lint k, int m) {
    lint r = 1 % m;
    for (lint x = a % m; k > 0; k >>= 1, x = x * x % m)
        if (k & 1) r = r * x % m;
    return r;
}

void solve() {
    lint n, p;
    cin >> n >> p;
    vector<lint> A(n);
    rep (i, n) cin >> A[i];

    if (A[0] == A[1]) {
        cout << modpow(2, n - 1, p) * A[0] % p << endl;
        return;
    }

    vector<lint> sum(1 << n);
    rep (S, 1 << n) {
        rep (i, n) {
            if (S >> i & 1) sum[S] += A[i];
        }
    }

    lint ans = 0;
    rep (S, 1 << n) {
        if (S == 0) continue;

        lint evenness = INF;
        for (int T = S;; T = (T - 1) & S) {
            evenness = min(evenness, abs(sum[T] - sum[S & ~T]));
            if (T == 0) break;
        }
        ans = (ans + evenness) % p;
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    rep (_, t) {
        solve();
    }
    return 0;
}
