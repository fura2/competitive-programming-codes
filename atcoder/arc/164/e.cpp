#include "template.hpp"

// 解説を見ながら upsolve. むずかしい.
// https://atcoder.jp/contests/arc164/editorial/6630

// 数列 1, 2, ..., N の各項の間 (および両端) に仕切りを入れる.
//   | 1 | 2 | ... | N |
// 仕切りに左から順に 0, 1, ..., N と番号をつける.
// 深さ d-1 の区間 [L, R] を深さ d の二つの区間 [L, M], [M+1, R] に分けることを, [L, R] を仕切り M で切る, と考える.

// 区間 [l, r] に対するクエリについて考える.
// この区間は仕切り l-1 と r で区切られていて、このクエリを探索するときにアクセスする深さが最大になるのは,
// 仕切り l-1 または r を切るときに限られる. (そのような区間の深さ +1 までアクセスする.)
// 仕切り 0 と N は忘れてよい.
// 深さ d の完全二分木を考えると, これは 2^d - 1 個の葉でない頂点を持ち, それらに最大 2^d - 1 個の仕切りを割り当てられる.
// ゆえに, クエリに登場した l-1 と r の種類数を k として, k <= 2^d - 1 となる最小の d が求める d の値になる.

// c について考える.
// クエリに登場する仕切り l-1 と r を深さ d-1 の区間で切った回数の 2 倍が c にカウントされる.
// (*) 隣接する仕切り (x, x+1) を両方とも深さ d-1 の区間で切ることはできないことに注意.
// クエリに登場した l-1 と r の回数のヒストグラムを {a_0: h_0, ..., a_{k-1}: h_{k-1}} とおく.
// 各 h_i を, 完全二分木の 2^d - 1 個の頂点のうち, 深さ d-1 未満の頂点 (2^{d-1} - 1 個)
// または深さ d-1 の頂点 (2^{d-1} 個) のいずれかに割り当てて, 後者に割り当てた h_i の総和を最小化すればよい.
// ただし, (*) より, a_{i+1} == a_i + 1 となる h_i と h_{i+1} を同時に後者に割り当てることはできない.
// 逆に, 最適な割り当てに対しては, もとの完全二分木が復元できる. (なぜ?)

const int INF = 1 << 29;

int main() {
    int n, q; cin >> n >> q;
    map<int, int> hist;
    rep(q) {
        int l, r; cin >> l >> r;
        ++hist[l - 1];
        ++hist[r];
    }
    hist.erase(0);
    hist.erase(n);

    int k = hist.size();
    int d = 0;
    while ((1 << d) - 1 < k) d++;

    if (d == 0) {
        cout << d << " " << q << endl;
        return 0;
    }

    vector<int> a, h;
    for (auto [key, value] : hist) {
        a.emplace_back(key);
        h.emplace_back(value);
    }
    // dp[i][j][b] = (h_0, ..., h_i について, 深さ d-1 未満の頂点に j 個割り当てたときの最小スコア.
    //                b は h_i を深さ d-1 の頂点に割り当てたかどうか)
    vector dp(k + 1, vector(1 << (d - 1), vector(2, INF)));
    dp[0][0][0] = 0;
    rep(i, k) {
        rep(j, 1 << (d - 1)) {
            // h_i を深さ d-1 未満の頂点に割り当てる
            if (j + 1 <= (1 << (d - 1)) - 1) {
                chmin(dp[i + 1][j + 1][0], dp[i][j][0]);
                chmin(dp[i + 1][j + 1][0], dp[i][j][1]);
            }
            // h_i を深さ d-1 の頂点に割り当てる
            if ((i + 1) - j <= (1 << (d - 1))) {
                chmin(dp[i + 1][j][1], dp[i][j][0] + h[i]);
            }
        }
    }

    int c = INF;
    rep(j, 1 << (d - 1)) rep(b, 2) chmin(c, 2 * dp[k][j][b]);
    cout << d << " " << c << endl;

    return 0;
}
