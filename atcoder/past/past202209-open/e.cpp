#include "template.hpp"

int main() {
    int r, n, m, l;
    cin >> r >> n >> m >> l;
    vector<int> A(l);
    rep(i, l) cin >> A[i];

    int rnd = 0, cnt = 0, sum = 0;
    for (int a : A) {
        sum += a;
        cnt++;
        if (sum > n) {
            no();
            return 0;
        }
        if (sum == n || cnt == m) {
            rnd++;
            cnt = 0;
            sum = 0;
        }
    }
    yesno(rnd == r && cnt == 0);

    return 0;
}
