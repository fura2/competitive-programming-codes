#include "template.hpp"

int main() {
    string s;
    char c; cin >> s >> c;
    for (char a : s) {
        cout << a;
        if (a == c) cout << a;
    }

    return 0;
}
