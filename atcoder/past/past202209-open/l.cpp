#include "template.hpp"

const lint INF = 1LL << 61;

// i = 1, 2, ..., n をそれぞれ選ぶかどうか決めるときのスコアの最大値を求める.
// ただし, 選んだ i の個数が mod 3 で tar に等しくなるようにする.
// スコアは次のように計算される.
// - i を選ぶと A_i 点
// - 各 j = 1, 2, ..., m に対し, 0 <= i < Q_j なる i を選んだ個数が mod 3 で L_j に等しいなら P_j 点加点
lint f(const vector<lint> &A, const vector<lint> &P, const vector<int> &Q, const vector<int> &L, int tar) {
    int n = A.size(), m = P.size();

    vector<vector<int>> Idx(n + 1);
    rep(j, m) Idx[Q[j]].emplace_back(j);

    vector dp(n + 1, vector(3, -INF));
    dp[0][0] = 0;
    for (int j : Idx[0]) {
        if (L[j] == 0)
            dp[0][0] += P[j];
    }
    rep(i, n) {
        rep(x, 3) if (dp[i][x] != -INF) {
            chmax(dp[i + 1][x], dp[i][x]);                  // i を選ばない
            chmax(dp[i + 1][(x + 1) % 3], dp[i][x] + A[i]); // i を選ぶ
        }
        for (int j : Idx[i + 1]) {
            if (dp[i + 1][L[j]] != -INF)
                dp[i + 1][L[j]] += P[j];
        }
    }
    return dp[n][tar];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<lint> A(n), P(m);
    vector<int> Q(m), L(m), R(m);
    rep(i, n) cin >> A[i];
    rep(j, m) cin >> P[j] >> Q[j] >> L[j] >> R[j], Q[j]--;

    lint ans = 0;
    rep(tar, 3) {
        vector<lint> P2;
        vector<int> Q2, L2;
        rep(j, m) if ((L[j] + R[j]) % 3 == tar) {
            P2.emplace_back(P[j]);
            Q2.emplace_back(Q[j]);
            L2.emplace_back(L[j]);
        }
        chmax(ans, f(A, P2, Q2, L2, tar));
    }
    cout << ans << endl;

    return 0;
}
