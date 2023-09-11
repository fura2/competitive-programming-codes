#include "template.hpp"

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << min(x / a, y / b) << endl;

    return 0;
}
