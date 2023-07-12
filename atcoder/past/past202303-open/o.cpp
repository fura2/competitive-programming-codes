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

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    const int b = 700; // bucket size
    while (n % b != 0) {
        a.emplace_back(0);
        n++;
    }
    int m = n / b; // number of buckets
    vector B(m, vector(11, 0)); // histogram
    rep(i, m) rep(j, b) B[i][a[i * b + j]]++;
    vector<int> flag(m); // 0: evaluated, 1: asc sorted (lazy), 2: desc sorted (lazy)

    rep(q) {
        int type, l, r; cin >> type >> l >> r; l--;

        int il = l / b, jl = l % b;
        int ir = r / b, jr = r % b;

        // evaluate
        for (int i : {il, ir}) {
            if (flag[i] == 1) {
                int pos = i * b;
                rep(v, 11) rep(B[i][v]) a[pos] = v, pos++;
                flag[i] = 0;
            }
            else if (flag[i] == 2) {
                int pos = i * b;
                rrep(v, 11) rep(B[i][v]) a[pos] = v, pos++;
                flag[i] = 0;
            }
        }

        if (type == 1) {
            if (il == ir) {
                sort(a.begin() + il * b + jl, a.begin() + ir * b + jr);
            }
            else {
                // compute histogram
                int h[11] = {};
                rep(j, jl, b) h[a[il * b + j]]++;
                rep(i, il + 1, ir) rep(v, 11) h[v] += B[i][v];
                rep(j, jr) h[a[ir * b + j]]++;

                // update
                int v = 0;
                while (h[v] == 0) v++;
                rep(j, jl, b) {
                    B[il][a[il * b + j]]--;
                    B[il][v]++;
                    a[il * b + j] = v;
                    h[v]--;
                    while (v <= 10 && h[v] == 0) v++;
                }
                rep(i, il + 1, ir) {
                    int h2[11] = {}, sum = 0;
                    while (sum < b) {
                        h2[v] = min(h[v], b - sum);
                        sum += h2[v];
                        h[v] -= h2[v];
                        while (v <= 10 && h[v] == 0) v++;
                    }
                    rep(x, 11) B[i][x] = h2[x];
                    flag[i] = 1;
                }
                rep(j, jr) {
                    B[ir][a[ir * b + j]]--;
                    B[ir][v]++;
                    a[ir * b + j] = v;
                    h[v]--;
                    while (v <= 10 && h[v] == 0) v++;
                }
            }
        }
        else if (type == 2) {
            if (il == ir) {
                sort(a.begin() + il * b + jl, a.begin() + ir * b + jr);
                reverse(a.begin() + il * b + jl, a.begin() + ir * b + jr);
            }
            else {
                // compute histogram
                int h[11] = {};
                rep(j, jl, b) h[a[il * b + j]]++;
                rep(i, il + 1, ir) rep(v, 11) h[v] += B[i][v];
                rep(j, jr) h[a[ir * b + j]]++;

                // update
                int v = 10;
                while (h[v] == 0) v--;
                rep(j, jl, b) {
                    B[il][a[il * b + j]]--;
                    B[il][v]++;
                    a[il * b + j] = v;
                    h[v]--;
                    while (v >= 0 && h[v] == 0) v--;
                }
                rep(i, il + 1, ir) {
                    int h2[11] = {}, sum = 0;
                    while (sum < b) {
                        h2[v] = min(h[v], b - sum);
                        sum += h2[v];
                        h[v] -= h2[v];
                        while (v >= 0 && h[v] == 0) v--;
                    }
                    rep(x, 11) B[i][x] = h2[x];
                    flag[i] = 2;
                }
                rep(j, jr) {
                    B[ir][a[ir * b + j]]--;
                    B[ir][v]++;
                    a[ir * b + j] = v;
                    h[v]--;
                    while (v >= 0 && h[v] == 0) v--;
                }
            }
        }
        else {
            int ans;
            if (il == ir) {
                ans = accumulate(a.begin() + il * b + jl, a.begin() + ir * b + jr, 0);
            }
            else {
                // compute histogram
                int h[11] = {};
                rep(j, jl, b) h[a[il * b + j]]++;
                rep(i, il + 1, ir) rep(v, 11) h[v] += B[i][v];
                rep(j, jr) h[a[ir * b + j]]++;
                ans = 0;
                rep(v, 11) ans += h[v] * v;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
