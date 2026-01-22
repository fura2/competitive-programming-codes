// 経路復元 like な解法

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define impl_overload4(a, b, c, d, e, ...) e
#define impl_overload5(a, b, c, d, e, f, ...) f
#define impl_overload6(a, b, c, d, e, f, g, ...) g
#define impl_overload7(a, b, c, d, e, f, g, h, ...) h

// clang-format off
#define impl_rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define impl_rep3(i, a, b) impl_rep4(i, a, b, 1)
#define impl_rep2(i, n) impl_rep3(i, 0, n)
#define impl_rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) impl_overload4(__VA_ARGS__, impl_rep4, impl_rep3, impl_rep2, impl_rep1)(__VA_ARGS__)

#define impl_rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define impl_rrep3(i, a, b) impl_rrep4(i, a, b, 1)
#define impl_rrep2(i, n) impl_rrep3(i, 0, n)
#define rrep(...) impl_overload4(__VA_ARGS__, impl_rrep4, impl_rrep3, impl_rrep2)(__VA_ARGS__)
// clang-format on

#define all(v) std::begin(v), std::end(v)

template<typename T>
constexpr int bit(T x, unsigned int k) {
    return (x >> k) & 1;
}

template<typename T>
constexpr bool chmax(T& a, const T& b) {
    return a < b ? a = b, true : false;
}
template<typename T>
constexpr bool chmin(T& a, const T& b) {
    return a > b ? a = b, true : false;
}

void yesno(bool b) {
    std::cout << (b ? "Yes" : "No") << "\n";
}
void yes() {
    yesno(true);
}
void no() {
    yesno(false);
}

struct Setup {
    Setup() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(11);
    }
} setup;

#ifdef LOCAL
#ifndef TEMPLATE_LOCAL_HPP
#define TEMPLATE_LOCAL_HPP

#include "template.hpp"

// clang-format off
#define impl_show1(a) { std::clog << #a << " = " << (a) << endl; }
#define impl_show2(a, ...) { std::clog << #a << " = " << (a) << ", "; impl_show1(__VA_ARGS__); }
#define impl_show3(a, ...) { std::clog << #a << " = " << (a) << ", "; impl_show2(__VA_ARGS__); }
#define impl_show4(a, ...) { std::clog << #a << " = " << (a) << ", "; impl_show3(__VA_ARGS__); }
#define impl_show5(a, ...) { std::clog << #a << " = " << (a) << ", "; impl_show4(__VA_ARGS__); }
#define impl_show6(a, ...) { std::clog << #a << " = " << (a) << ", "; impl_show5(__VA_ARGS__); }
#define impl_show7(a, ...) { std::clog << #a << " = " << (a) << ", "; impl_show6(__VA_ARGS__); }
#define show(...) { std::clog << "\033[33m"; \
                    impl_overload7(__VA_ARGS__, impl_show7, impl_show6, impl_show5, impl_show4, impl_show3, impl_show2, impl_show1)(__VA_ARGS__) \
                    std::clog << "\033[0m" << std::flush; }
// clang-format on

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::tuple<T, U>& t) {
    os << "(" << std::get<0>(t) << ", " << std::get<1>(t) << ")";
    return os;
}

template<typename T, typename U, typename V>
std::ostream& operator<<(std::ostream& os, const std::tuple<T, U, V>& t) {
    os << "(" << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << ")";
    return os;
}

template<typename T, typename U, typename V, typename W>
std::ostream& operator<<(std::ostream& os, const std::tuple<T, U, V, W>& t) {
    os << "(" << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << ", " << std::get<3>(t)
       << ")";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e: v) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "]";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e: s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e: s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e: s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& m) {
    os << "{";
    bool first = true;
    for (const auto& [k, v]: m) {
        if (!first) os << ", ";
        first = false;
        os << k << ": " << v;
    }
    os << "}";
    return os;
}

#endif // TEMPLATE_LOCAL_HPP
#else
#define show(...) ((void)0)
#endif

using uint = unsigned int;
using lint = long long;
using ulint = unsigned long long;

using namespace std;

#endif // TEMPLATE_HPP

const lint INF = 1LL << 61;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> c(n);
    vector<lint> v(n);
    rep (i, n) cin >> c[i] >> v[i];

    vector dp(n + 1, vector(w + 1, -INF));
    dp[0][0] = 0;
    rep (i, n) {
        rep (x, w + 1) {
            chmax(dp[i + 1][x], dp[i][x]);
            if (x >= c[i]) {
                chmax(dp[i + 1][x], dp[i][x - c[i]] + v[i]);
            }
        }
    }
    lint opt = *max_element(all(dp[n]));

    vector vis(n + 1, vector(w + 1, false));
    rep (x, w + 1) {
        if (dp[n][x] == opt) {
            vis[n][x] = true;
        }
    }
    vector<bool> use(n), pass(n);
    rrep (i, n) {
        rep (x, w + 1) {
            if (!vis[i + 1][x]) continue;

            vector<int> prev;
            if (dp[i + 1][x] == dp[i][x]) {
                prev.emplace_back(x);
            }
            if (x >= c[i] && dp[i + 1][x] == dp[i][x - c[i]] + v[i]) {
                prev.emplace_back(x - c[i]);
            }

            for (int y: prev) {
                if (!vis[i][y]) {
                    vis[i][y] = true;
                }
                if (y == x) {
                    pass[i] = true;
                }
                else { // y < x
                    use[i] = true;
                }
            }
        }
    }

    string ans;
    rep (i, n) {
        if (use[i] && pass[i])
            ans += 'B';
        else if (use[i])
            ans += 'A';
        else // pass[i]
            ans += 'C';
    }
    cout << ans << endl;

    return 0;
}
