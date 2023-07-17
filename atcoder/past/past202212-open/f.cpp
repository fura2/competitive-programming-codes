#include "template.hpp"

int main() {
    lint n, a, b, c, d, x1, x2;
    char point;
    cin >> n >> a >> b >> c >> d >> x1 >> point >> x2;
    lint x = x1 * 1000 + x2;

    cout << max((1000 * (a + 2 * b + 3 * c + 4 * d) - n * x + (x - 1000 - 1)) / (x - 1000), 0LL) << endl;

    return 0;
}
