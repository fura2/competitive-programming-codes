#include "template.hpp"

// 構成する数列を A とすると, Sに関する条件から, A は先頭 K 項の繰り返しになることが分かる.
//   A = (A_1, ..., A_K, A_{K+1}=A_1, ..., A_{2K}=A_K, ..., A_{N+M})
// A をサイズ K のブロックに分割する.
// - サイズ K のブロックの個数を L = floor((N+M)/K) とおく.
// - 余った部分のサイズを R = ((N+M) mod K) とおく.
// 余った部分に含まれる 1 の個数を y とすると, LS+y=M が必要なので, y が決まる.
// その y の値を実現するような A の先頭 K 項の決め方が存在するかを調べればよい.
// 実現可能は y の範囲は
//   max{0, R-(K-S)} ≦ y ≦ min{R, S}
// で与えられる. (1 をサイズ K のブロックの右に寄せる場合と左に寄せる場合)

int main() {
    lint n, m, k, x;
    cin >> n >> m >> k >> x;

    lint l = (n + m) / k;
    lint r = (n + m) % k;
    lint y = m - l * x;
    if (max(0LL, r - (k - x)) <= y and y <= min(r, x)) {
        vector<lint> ans(k);
        rep (i, y) ans[i] = 1;
        rep (i, x - y) ans[k - 1 - i] = 1;

        yes();
        rep (i, n + m) cout << ans[i % k];
        cout << endl;
    }
    else {
        no();
    }

    return 0;
}
