#include "template.hpp"

int main() {
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    cout << ((x + a * c) * b < x * a   ? "Hare"
             : (x + a * c) * b > x * a ? "Tortoise"
                                       : "Tie")
         << endl;

    return 0;
}
