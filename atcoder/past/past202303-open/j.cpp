#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define _overload4(a, b, c, d, e, ...) e
#define _overload5(a, b, c, d, e, f, ...) f
#define _overload6(a, b, c, d, e, f, g, ...) g

#define _rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define _rep3(i, a, b) _rep4(i, a, b, 1)
#define _rep2(i, n) _rep3(i, 0, n)
#define _rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) _overload4(__VA_ARGS__, _rep4, _rep3, _rep2, _rep1)(__VA_ARGS__)

#define _rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define _rrep3(i, a, b) _rrep4(i, a, b, 1)
#define _rrep2(i, n) _rrep3(i, 0, n)
#define rrep(...) _overload4(__VA_ARGS__, _rrep4, _rrep3, _rrep2)(__VA_ARGS__)

#define all(v) begin(v), end(v)

#define _show1(a) { std::clog << #a << " = " << a << endl; }
#define _show2(a, ...) { std::clog << #a << " = " << a << ", "; _show1(__VA_ARGS__); }
#define _show3(a, ...) { std::clog << #a << " = " << a << ", "; _show2(__VA_ARGS__); }
#define _show4(a, ...) { std::clog << #a << " = " << a << ", "; _show3(__VA_ARGS__); }
#define _show5(a, ...) { std::clog << #a << " = " << a << ", "; _show4(__VA_ARGS__); }
#define _show6(a, ...) { std::clog << #a << " = " << a << ", "; _show5(__VA_ARGS__); }
#define show(...) _overload6(__VA_ARGS__, _show6, _show5, _show4, _show3, _show2, _show1)(__VA_ARGS__)

using lint = long long;

template<typename T>
constexpr inline int bit(T x, unsigned int k) { return (x >> k) & 1; }

template<typename C>
long ssize(const C& c) { return std::size(c); }  // workaround until C++20

void yes() { std::cout << "Yes\n"; }
void no() { std::cout << "No\n"; }
void yesno(bool b) { std::cout << (b ? "Yes" : "No") << "\n"; }

template<class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e : v) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "]";
    return os;
}

struct Setup {
    Setup() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(11);
    }
} _setup;

using namespace std;

class rolling_hash {
    static const long long base = 10007, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    inline static vector<long long> pow1 = { 1 }, pow2 = { 1 };
    int len;
    vector<long long> h1, h2;

    static void allocate(int len) {
        if (pow1.size() <= len) {
            int k = pow1.size();
            pow1.resize(len + 1);
            pow2.resize(len + 1);
            for (; k <= len; k++) {
                pow1[k] = pow1[k - 1] * base % mod1;
                pow2[k] = pow2[k - 1] * base % mod2;
            }
        }
    }

public:
    using hash_type = tuple<long long, long long, int>;
    rolling_hash() {}
    rolling_hash(const string& s):len(s.length()), h1(len + 1), h2(len + 1) {
        rep(i, len) {
            h1[i + 1] = (h1[i] * base + s[i]) % mod1;
            h2[i + 1] = (h2[i] * base + s[i]) % mod2;
        }
    }
    template<class T>
    rolling_hash(const vector<T>& a):len(a.size()), h1(len + 1), h2(len + 1) {
        rep(i, len) {
            h1[i + 1] = (h1[i] * base + a[i]) % mod1; if (h1[i + 1] < 0) h1[i + 1] += mod1;
            h2[i + 1] = (h2[i] * base + a[i]) % mod2; if (h2[i + 1] < 0) h2[i + 1] += mod2;
        }
    }
    hash_type get_hash(int l, int r)const {
        assert(0 <= l && l <= r && r <= len);
        allocate(r - l);
        auto res1 = (h1[r] - h1[l] * pow1[r - l]) % mod1; if (res1 < 0) res1 += mod1;
        auto res2 = (h2[r] - h2[l] * pow2[r - l]) % mod2; if (res2 < 0) res2 += mod2;
        return { res1, res2, r - l };
    }
    static hash_type get_hash(const string& s) {
        long long res1 = 0, res2 = 0;
        rep(i, s.length()) {
            res1 = (res1 * base + s[i]) % mod1;
            res2 = (res2 * base + s[i]) % mod2;
        }
        return { res1, res2, s.length() };
    }
    template<class T>
    static hash_type get_hash(const vector<T>& a) {
        long long res1 = 0, res2 = 0;
        rep(i, a.size()) {
            res1 = (res1 * base + a[i]) % mod1;
            res2 = (res2 * base + a[i]) % mod2;
        }
        return { res1, res2, a.size() };
    }
    friend hash_type operator*(const hash_type&, const hash_type&);
};

rolling_hash::hash_type operator*(const rolling_hash::hash_type& H1, const rolling_hash::hash_type& H2) {
    long long h11, h12, h21, h22;
    int len1, len2;
    tie(h11, h12, len1) = H1;
    tie(h21, h22, len2) = H2;

    rolling_hash::allocate(len2);
    long long res1 = (h11 * rolling_hash::pow1[len2] + h21) % rolling_hash::mod1;
    long long res2 = (h12 * rolling_hash::pow2[len2] + h22) % rolling_hash::mod2;
    return { res1, res2, len1 + len2 };
}

int main() {
    int h, w; cin >> h >> w;
    vector<string> S(h), T(h);
    rep(i, h) cin >> S[i];
    rep(i, h) cin >> T[i];

    vector<rolling_hash> R1(h), R2(h);
    rep(i, h) {
        R1[i] = rolling_hash(S[i]);
        R2[i] = rolling_hash(T[i]);
    }

    rep(j, w) {
        bool ok = true;
        rep(i, h) {
            if (R1[i].get_hash(0, w) != R2[i].get_hash(j, w) * R2[i].get_hash(0, j)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            yes();
            return 0;
        }
    }
    no();

    return 0;
}
