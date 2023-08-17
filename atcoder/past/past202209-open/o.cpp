#include "template.hpp"

class mint {
    static const int MOD = 998244353;
    int x;

  public:
    mint() : x(0) {}
    mint(long long y) {
        x = y % MOD;
        if (x < 0)
            x += MOD;
    }

    mint &operator+=(const mint &m) {
        x += m.x;
        if (x >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator-=(const mint &m) {
        x -= m.x;
        if (x < 0)
            x += MOD;
        return *this;
    }
    mint &operator*=(const mint &m) {
        x = (long long)x * m.x % MOD;
        return *this;
    }
    mint &operator/=(const mint &m) { return *this *= inverse(m); }
    mint operator+(const mint &m) const { return mint(*this) += m; }
    mint operator-(const mint &m) const { return mint(*this) -= m; }
    mint operator*(const mint &m) const { return mint(*this) *= m; }
    mint operator/(const mint &m) const { return mint(*this) /= m; }
    mint operator-() const { return -x; }

    friend mint inverse(const mint &m) {
        int a = m.x, b = MOD, u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return u;
    }

    friend istream &operator>>(istream &is, mint &m) {
        long long t;
        is >> t;
        m = t;
        return is;
    }
    friend ostream &operator<<(ostream &os, const mint &m) { return os << m.x; }
    int to_int() const { return x; }
};

mint operator+(long long x, const mint &m) { return mint(x) + m; }
mint operator-(long long x, const mint &m) { return mint(x) - m; }
mint operator*(long long x, const mint &m) { return mint(x) * m; }
mint operator/(long long x, const mint &m) { return mint(x) / m; }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(1 << n), B(1 << n);
    rep(S, 1 << n) cin >> A[S];
    rep(S, 1 << n) cin >> B[S];

    vector cumA(1 << n, vector(n + 1, mint(0))); // cumA[S][p] = Σ_{T⊂S, popcount(A_T)=p} A_T
    vector cumB(1 << n, vector(n + 1, mint(0)));
    rep(S, 1 << n) {
        cumA[S][__builtin_popcount(S)] += A[S];
        cumB[S][__builtin_popcount(S)] += B[S];
    }
    rep(p, n + 1) rep(i, n) rep(S, 1 << n) { // fast zeta transform
        if (bit(S, i) == 0) {
            cumA[S | (1 << i)][p] += cumA[S][p];
            cumB[S | (1 << i)][p] += cumB[S][p];
        }
    }

    // g(S, p) = Σ_{X∪Y⊂S, popcount(A_X)+popcount(B_Y)=p} A_X * B_Y
    vector g(1 << n, vector(2 * n + 1, mint(0)));
    rep(S, 1 << n) {
        rep(i, n + 1) rep(j, n + 1) {
            g[S][i + j] += cumA[S][i] * cumB[S][j];
        }
    }

    // f(S, p) = Σ_{X∪Y=S, popcount(A_X)+popcount(B_Y)=p} A_X * B_Y
    vector f(1 << n, vector(2 * n + 1, mint(0)));
    rep(p, 2 * n + 1) {
        rep(S, 1 << n) f[S][p] = g[S][p];
        rrep(i, n) rrep(S, 1 << n) { // fast moebius transform
            if (bit(S, i) == 0) {
                f[S | (1 << i)][p] -= f[S][p];
            }
        }
    }

    rep(q) {
        int x, y;
        cin >> x >> y;
        cout << f[x][y] << "\n";
    }

    return 0;
}
