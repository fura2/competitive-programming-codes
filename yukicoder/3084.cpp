/*
f = {
    '': 0,
    '0': 1,
    '00': 4,
    '000': 16,
    '0000': 24,
    '00000': 30,
    '000000': 45,
    '0000000': 161,
    '0000001': 91,
    '00000010': 144,
    '000001': 82,
    '0000010': 147,
    '00001': 51,
    '000010': 152,
    '000011': 59,
    '0001': 18,
    '00010': 67,
    '000101': 110,
    '00011': 54,
    '000110': 69,
    '0001101': 77,
    '00011011': 157,
    '000111': 81,
    '0001110': 112,
    '001': 10,
    '0010': 12,
    '00100': 15,
    '001000': 75,
    '0010001': 166,
    '001001': 26,
    '00101': 32,
    '001010': 109,
    '0010100': 155,
    '001011': 106,
    '0010111': 111,
    '00101110': 127,
    '0011': 14,
    '00110': 89,
    '001100': 105,
    '001101': 93,
    '0011010': 170,
    '0011011': 129,
    '00111': 128,
    '001110': 163,
    '01': 3,
    '010': 20,
    '0100': 23,
    '01000': 76,
    '010000': 126,
    '0100001': 146,
    '010001': 135,
    '01001': 150,
    '010011': 164,
    '0101': 31,
    '01010': 40,
    '010100': 70,
    '0101001': 90,
    '010101': 114,
    '0101011': 123,
    '01010110': 138,
    '01011': 47,
    '010110': 61,
    '0101101': 65,
    '01011010': 151,
    '01011011': 100,
    '010110111': 158,
    '011': 6,
    '0110': 17,
    '01100': 21,
    '011000': 60,
    '0110000': 72,
    '0110001': 96,
    '01100010': 121,
    '011000101': 139,
    '01100011': 107,
    '011001': 33,
    '0110010': 49,
    '0110011': 169,
    '01101': 37,
    '011010': 149,
    '011011': 53,
    '0110111': 113,
    '0111': 7,
    '01110': 19,
    '011100': 102,
    '011101': 64,
    '0111011': 98,
    '01111': 116,
    '011110': 133,
    '011111': 132,
    '1': 2,
    '10': 5,
    '100': 27,
    '1000': 38,
    '10000': 57,
    '100000': 71,
    '1000000': 85,
    '10000001': 103,
    '1000001': 145,
    '10000011': 165,
    '100001': 160,
    '10001': 42,
    '100010': 52,
    '100011': 63,
    '1000110': 66,
    '1001': 29,
    '10010': 48,
    '100100': 50,
    '1001000': 156,
    '1001001': 119,
    '10011': 92,
    '100110': 101,
    '1001100': 171,
    '101': 8,
    '1010': 22,
    '10100': 34,
    '101000': 87,
    '1010000': 167,
    '101001': 58,
    '1010010': 137,
    '1010011': 86,
    '10101': 28,
    '101010': 55,
    '1010101': 79,
    '10101011': 108,
    '101010110': 130,
    '101011': 141,
    '1011': 11,
    '10110': 35,
    '101100': 159,
    '101101': 73,
    '1011010': 99,
    '10110101': 115,
    '10111': 13,
    '101110': 84,
    '101111': 97,
    '1011110': 117,
    '1011111': 148,
    '10111110': 153,
    '11': 9,
    '110': 39,
    '1100': 43,
    '11000': 46,
    '110001': 62,
    '1100010': 143,
    '1100011': 95,
    '11001': 44,
    '110010': 56,
    '1100100': 124,
    '11001001': 142,
    '1100101': 172,
    '110011': 74,
    '1101': 80,
    '11010': 83,
    '110100': 88,
    '1101000': 168,
    '110101': 131,
    '1101010': 154,
    '11011': 104,
    '110110': 118,
    '1101101': 134,
    '111': 25,
    '1110': 41,
    '11100': 125,
    '111001': 162,
    '11101': 68,
    '111010': 120,
    '1110101': 136,
    '111011': 78,
    '1110110': 94,
    '1111': 36,
    '11110': 140,
    '11111': 122,
}

g = [None] * 173
for k, v in f.items():
    g[v] = k
g.append(g[10])

s = ''.join(g)
while len(s) >= 8:
    print(chr(int(s[:8], base=2)), end='')
    s = s[8:]

# Roses are red
# Violets are blue
# Calculate and output
# the following value
# \sum_{i=1}^N \sum_{j=i+1}^N ((A_i+A_j) mod 998244353)
*/

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
#include "template_local.hpp"
#else
#define show(...) ((void)0)
#endif

using uint = unsigned int;
using lint = long long;
using ulint = unsigned long long;

using namespace std;

#endif // TEMPLATE_HPP

template<class G>
class Fenwick_tree {
    vector<G> a;

  public:
    Fenwick_tree(int n = 0) {
        build(n);
    }
    Fenwick_tree(const vector<G>& a) {
        build(a);
    }
    void build(int n) {
        a.assign(n, G{});
    }
    void build(const vector<G>& a) {
        this->a = a;
        for (int i = 1; i <= a.size(); i++)
            if (i + (i & -i) <= a.size()) (this->a)[i + (i & -i) - 1] += (this->a)[i - 1];
    }
    void add(int i, const G& val) {
        for (i++; i <= a.size(); i += i & -i) a[i - 1] += val;
    }
    G sum(int l, int r) const {
        if (l == 0) {
            G res{};
            for (; r > 0; r -= r & -r) res += a[r - 1];
            return res;
        }
        return sum(0, r) - sum(0, l);
    }
    int lower_bound(G val) const {
        if (!(G{} < val)) return 0;
        int x = 0, k;
        for (k = 1; k <= a.size(); k <<= 1)
            ;
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= a.size() && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
        return x;
    }
    int upper_bound(G val) const {
        if (val < G{}) return 0;
        int x = 0, k;
        for (k = 1; k <= a.size(); k <<= 1)
            ;
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= a.size() && !(val < a[x + k - 1])) val -= a[x + k - 1], x += k;
        return x;
    }
};

const lint M = 998244353;

int main() {
    int n;
    cin >> n;
    vector<lint> A(n);
    rep (i, n) {
        cin >> A[i];
        A[i] %= M;
    }

    // compress coordinates
    vector<lint> X = A;
    sort(all(X));
    X.erase(unique(all(X)), end(X));
    vector<lint> P(n);
    rep (i, n) {
        P[i] = lower_bound(all(X), A[i]) - begin(X);
    }

    lint cnt = 0;
    Fenwick_tree<lint> F(size(X));
    rrep (i, n) {
        // count j s.t. j > i and A_i + A_j >= M
        int idx = lower_bound(all(X), M - A[i]) - begin(X);
        cnt += F.sum(idx, size(X));
        F.add(P[i], 1);
    }

    lint ans = (n - 1) * accumulate(all(A), 0LL);
    ans -= cnt * M;
    cout << ans << endl;

    return 0;
}
