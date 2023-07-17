#include "template.hpp"

int main() {
    lint a, b, x; cin >> a >> b >> x;

    lint ten = 1;
    rep(17) ten *= 10;

    lint ans = 0, digitsum = 0;
    rep(18) {
        rrep(d, 10) {
            digitsum += d;
            ans += d * ten;
            if (ans <= (x - b * digitsum) / a) break;
            ans -= d * ten;
            digitsum -= d;
        }
        ten /= 10;
    }
    cout << min(ans, 1000000000LL) << endl;

    return 0;
}
