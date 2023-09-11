#include "template.hpp"

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double lo = 1, hi = 2;
    rep (50) {
        double mi = (lo + hi) / 2;
        (a * pow(mi, 5) + b * mi + c < 0 ? lo : hi) = mi;
    }
    cout << lo << endl;

    return 0;
}
