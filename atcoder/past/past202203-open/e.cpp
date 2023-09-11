#include "template.hpp"

int D[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    string s;
    cin >> s;

    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(5, 2));
    int d = stoi(s.substr(8));

    while (true) {
        char t[16];
        sprintf(t, "%04d/%02d/%02d", y, m, d);
        string tt = t;
        if (set<char>(all(tt)).size() == 3) {
            cout << tt << endl;
            break;
        }

        d++;
        if (d > D[m]) d = 1, m++;
        if (m > 12) m = 1, y++;
    }

    return 0;
}
