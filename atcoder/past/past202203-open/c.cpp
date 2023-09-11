#include "template.hpp"

int main() {
    string s;
    cin >> s;

    char c = 'a' - 1;
    while (s.size() > 3) {
        c++;
        s = s.substr(0, s.size() - 3);
    }
    cout << s << c << endl;

    return 0;
}
