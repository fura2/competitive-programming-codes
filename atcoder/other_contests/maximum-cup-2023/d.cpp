#include "template.hpp"

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (ssize(s) % 2 != n % 2) {
        cout << "S" << endl;
        return 0;
    }

    int f[128];
    f['A'] = 3;
    f['C'] = 2;
    f['G'] = 1;
    f['T'] = 0;
    int x = 0;
    for (char c : s) x ^= f[c];

    cout << (x == 0 ? "U" : "S") << endl;

    return 0;
}
