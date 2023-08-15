#include "template.hpp"

int main() {
    string s;
    cin >> s;
    int n = s.size();
    cout << (n <= 2 ? "0" : s.substr(0, n - 2)) << endl;

    return 0;
}
