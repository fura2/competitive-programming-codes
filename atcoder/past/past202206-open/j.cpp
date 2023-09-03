#include "template.hpp"

tuple<int, int, int> parse(string s) {
    return {stoi(s.substr(0, 4)), stoi(s.substr(5, 2)), stoi(s.substr(8))};
}

int weekday(int y, int m, int d) { // Zeller
    if (m <= 2) m += 12, y--;
    int C = y / 100;
    int Y = y % 100;
    int Gamma = -2 * C + C / 4;
    return ((d + 26 * (m + 1) / 10 + Y + Y / 4 + Gamma) % 7 + 7) % 7;
}

bool is_leap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return y % 4 == 0;
}

const int D[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    auto [y1, m1, d1] = parse(s1);
    auto [y2, m2, d2] = parse(s2);

    int ans = 0;
    while (tuple(y1, m1, d1) <= tuple(y2, m2, d2)) {
        int w = weekday(y1, m1, d1);
        if (w == 0 or w == 1) ans++;
        d1++;
        if (d1 > D[m1] + ((is_leap(y1) and m1 == 2) ? 1 : 0)) d1 = 1, m1++;
        if (m1 > 12) m1 = 1, y1++;
    }
    cout << ans << endl;

    return 0;
}
