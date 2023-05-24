#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0;i < (n);i++)
#define dbg(v) for (const auto& e : v) { cout << e << ' '; } cout << endl;

using namespace std;

class mint {
    static const int MOD = 1e9 + 7;
    int x;
public:
    mint():x(0) {}
    mint(long long y) { x = y % MOD; if (x < 0) x += MOD; }

    mint& operator+=(const mint& m) { x += m.x; if (x >= MOD) x -= MOD; return *this; }
    mint& operator-=(const mint& m) { x -= m.x; if (x < 0) x += MOD; return *this; }
    mint& operator*=(const mint& m) { x = (long long)x * m.x % MOD; return *this; }
    mint& operator/=(const mint& m) { return *this *= inverse(m); }
    mint operator+(const mint& m)const { return mint(*this) += m; }
    mint operator-(const mint& m)const { return mint(*this) -= m; }
    mint operator*(const mint& m)const { return mint(*this) *= m; }
    mint operator/(const mint& m)const { return mint(*this) /= m; }
    mint operator-()const { return -x; }

    friend mint inverse(const mint& m) {
        int a = m.x, b = MOD, u = 1, v = 0;
        while (b > 0) { int t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        return u;
    }

    friend istream& operator>>(istream& is, mint& m) { long long t; is >> t; m = t; return is; }
    friend ostream& operator<<(ostream& os, const mint& m) { return os << m.x; }
    int to_int()const { return x; }
};

mint operator+(long long x, const mint& m) { return mint(x) + m; }
mint operator-(long long x, const mint& m) { return mint(x) - m; }
mint operator*(long long x, const mint& m) { return mint(x) * m; }
mint operator/(long long x, const mint& m) { return mint(x) / m; }

using poly = vector<mint>;
poly operator*(const poly& f, const poly& g) {
    int m = f.size(), n = g.size();
    poly h(m + n - 1);
    rep(i, m) rep(j, n) h[i + j] += f[i] * g[j];
    return h;
}

mint bostan_mori(const poly& p, const poly& q, int k) {
    if (k == 0) return p[0] / q[0];

    int deg = q.size() - 1;

    poly q_neg(deg + 1);
    rep(i, deg + 1) q_neg[i] = (i % 2 == 0 ? q[i] : -q[i]);

    poly u = p * q_neg, v = q * q_neg;
    poly u_even(deg), u_odd(deg), v_even(deg + 1);
    rep(i, deg) {
        u_even[i] = u[2 * i];
        u_odd[i] = u[2 * i + 1];
    }
    rep(i, deg + 1) {
        v_even[i] = v[2 * i];
    }

    return bostan_mori(k % 2 == 0 ? u_even : u_odd, v_even, k / 2);
}

int main() {
    int k, n;
    cin >> k >> n;

    poly g(k + 1); // denominator
    g[0] = 1;
    rep(i, k) g[i + 1] = -1;
    poly f = g * poly(k, 1); // numerator
    f.resize(k);

    // [x^{n-1}]f(x)/g(x)
    cout << bostan_mori(f, g, n - 1) << endl;

    return 0;
}
