#include "template.hpp"

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << (a * d < b * c ? "<>"[b * d > 0 ? 0 : 1] : a * d == b * c ? '=' : "><"[b * d > 0 ? 0 : 1]) << endl;

    return 0;
}
