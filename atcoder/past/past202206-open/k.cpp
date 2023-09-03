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

mint f(string s) {
    int n = s.size();

    // nxt[i][c] = (s[0, i) まで見たときの, 次に来る文字 c の位置)
    vector nxt(n + 1, vector(26, -1));
    rrep (i, n) {
        rep (c, 26) {
            nxt[i][c] = nxt[i + 1][c];
        }
        nxt[i][s[i] - 'a'] = i;
    }

    vector<mint> dp(n + 1);
    dp[0] = 1;
    rep (i, n) {
        rep (c, 26) {
            if (nxt[i][c] != -1) dp[nxt[i][c] + 1] += dp[i];
        }
    }
    return accumulate(all(dp), mint(0));
}

mint g(string s, string t) {
    int m = s.size(), n = t.size();

    vector nxt_s(m + 1, vector(26, -1));
    vector nxt_t(n + 1, vector(26, -1));
    rrep (i, m) {
        rep (c, 26) {
            nxt_s[i][c] = nxt_s[i + 1][c];
        }
        nxt_s[i][s[i] - 'a'] = i;
    }
    rrep (j, n) {
        rep (c, 26) {
            nxt_t[j][c] = nxt_t[j + 1][c];
        }
        nxt_t[j][t[j] - 'a'] = j;
    }

    vector dp(m + 1, vector<mint>(n + 1));
    dp[0][0] = 1;
    rep (i, m) {
        rep (j, n) {
            rep (c, 26) {
                if (nxt_s[i][c] != -1 and nxt_t[j][c] != -1) {
                    dp[nxt_s[i][c] + 1][nxt_t[j][c] + 1] += dp[i][j];
                }
            }
        }
    }

    mint ans = 0;
    rep (i, m + 1) {
        rep (j, n + 1) {
            ans += dp[i][j];
        }
    }
    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << f(s) + f(t) - g(s, t) - 1 << endl;

    return 0;
}
