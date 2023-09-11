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

int n, k;

mint f(vector<int> A) {
    mint res = 0;
    rep (i, n) {
        res += A[i] * (choose(i + 1, k) - choose(i, k));
    }
    res /= choose(n, k);
    return res;
}

int main() {
    cin >> n >> k;
    vector<int> A(n);
    rep (i, n) cin >> A[i];
    sort(all(A));

    auto B = A;
    rep (i, n) B[i] *= -1;
    sort(all(B));

    cout << f(A) + f(B) << endl;

    return 0;
}
