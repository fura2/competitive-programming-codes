#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const double PI = acos(-1);

int main() {
    double h, r;
    cin >> h >> r;
    double ans = -8.245 + 6.807 * h + 7.073 * 2 * PI * r;
    cout << setprecision(10) << ans << endl;
    return 0;
}
