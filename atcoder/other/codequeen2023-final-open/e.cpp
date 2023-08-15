#include "template.hpp"

const lint INF = 1LL << 61;

int main() {
    int n;
    cin >> n;
    vector<lint> A(n);
    rep(i, n) cin >> A[i];

    // dp0[i] = (A_i まで見たときのスコアの最大値)
    // dp1[i] = (A_i まで見て, 最後の連続部分列については + だけ選び済みのときのスコアの最大値)
    // dp2[i] = (A_i まで見て, 最後の連続部分列については - だけ選び済みのときのスコアの最大値)
    vector<lint> dp0(n + 1), dp1(n + 1), dp2(n + 1);
    dp0[0] = 0;
    dp1[0] = -INF;
    dp2[0] = -INF;
    rep(i, n) {
        dp0[i + 1] = dp0[i];
        dp1[i + 1] = dp1[i];
        dp2[i + 1] = dp2[i];
        chmax(dp0[i + 1], dp1[i] - A[i]);
        chmax(dp0[i + 1], dp2[i] + A[i]);
        chmax(dp1[i + 1], dp0[i] + A[i]);
        chmax(dp2[i + 1], dp0[i] - A[i]);
    }
    cout << dp0[n] << endl;

    return 0;
}
