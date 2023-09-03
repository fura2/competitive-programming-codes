#include "template.hpp"

int main() {
    lint n;
    cin >> n;

    lint m = ceil(sqrt((long double)n));
    n -= (m - 1) * (m - 1) + 1;
    cout << (n < m ? m - n : n - m + 2) << endl;

    return 0;
}
