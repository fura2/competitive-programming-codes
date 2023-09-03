#include "template.hpp"

class mint {
    static const int MOD = 998244353;
    int x;

  public:
    mint(): x(0) {}
    mint(long long y) {
        x = y % MOD;
        if (x < 0) x += MOD;
    }

    mint& operator+=(const mint& m) {
        x += m.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& m) {
        x -= m.x;
        if (x < 0) x += MOD;
        return *this;
    }
    mint& operator*=(const mint& m) {
        x = (long long)x * m.x % MOD;
        return *this;
    }
    mint& operator/=(const mint& m) {
        return *this *= inverse(m);
    }
    mint operator+(const mint& m) const {
        return mint(*this) += m;
    }
    mint operator-(const mint& m) const {
        return mint(*this) -= m;
    }
    mint operator*(const mint& m) const {
        return mint(*this) *= m;
    }
    mint operator/(const mint& m) const {
        return mint(*this) /= m;
    }
    mint operator-() const {
        return -x;
    }

    friend mint inverse(const mint& m) {
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

    friend istream& operator>>(istream& is, mint& m) {
        long long t;
        is >> t;
        m = t;
        return is;
    }
    friend ostream& operator<<(ostream& os, const mint& m) {
        return os << m.x;
    }
    int to_int() const {
        return x;
    }
};

mint operator+(long long x, const mint& m) {
    return mint(x) + m;
}
mint operator-(long long x, const mint& m) {
    return mint(x) - m;
}
mint operator*(long long x, const mint& m) {
    return mint(x) * m;
}
mint operator/(long long x, const mint& m) {
    return mint(x) / m;
}

mint pow(mint m, long long k) {
    mint res = 1;
    for (; k > 0; k >>= 1, m *= m)
        if (k & 1) res *= m;
    return res;
}

mint factorial(int n) {
    static vector<mint> memo = {1};
    if (memo.size() <= n) {
        int k = memo.size();
        memo.resize(n + 1);
        for (; k <= n; k++) memo[k] = memo[k - 1] * k;
    }
    return memo[n];
}

mint factorial_inverse(int n) {
    static vector<mint> memo = {1};
    if (memo.size() <= n) {
        int k = memo.size();
        memo.resize(n + 1);
        memo[n] = inverse(factorial(n));
        for (int i = n; i > k; i--) memo[i - 1] = memo[i] * i;
    }
    return memo[n];
}

mint choose(int n, int k, int type = 0) {
    if (k == 0) return 1;
    if (n < k) return 0;
    if (type == 0) {
        return factorial(n) * factorial_inverse(k) * factorial_inverse(n - k);
    }
    else {
        if (k > n - k) k = n - k;
        mint res = factorial_inverse(k);
        rep (i, k) res *= n - i;
        return res;
    }
}

mint multichoose(int n, int k, int type = 0) {
    return choose(n + k - 1, k, type);
}

int main() {
    int n;
    cin >> n;

    vector<mint> M2(2 * n); // M2[i] = 2^{-i}
    mint m2 = 1 / mint(2);
    M2[0] = 1;
    rep (i, 2 * n - 1) M2[i + 1] = M2[i] * m2;

    mint ans = 0;
    rep (i, 1, 2 * n - 2) {
        // p = (i, i+1 回目 (0-indexed) のゲームの前後で, Bobが逆転する
        //      (Aliceの点数 - Bobの点数 が 1 -> 0 -> -1 と変化する) 確率)
        mint p = 1;
        // i 回目以前のゲームで, Aliceは ceil(i / 2) 回勝ち, Bobは floor(i / 2) 回勝ち
        if (i % 2 == 0) continue;
        p *= choose(i, i / 2 + 1) * M2[i];
        // Aliceが二連敗
        if (i / 2 + 2 > n) continue;
        p *= M2[2];
        ans += 2 * p;
    }
    cout << ans << endl;

    return 0;
}
