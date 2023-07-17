#include "template.hpp"

int main() {
    int n, m;
    string s; cin >> n >> m >> s;

    vector<int> hand(n);
    int field = 0;
    rep(i, m) {
        hand[i % n]++;
        if (s[i] == '+') {
            hand[i % n] += field;
            field = 0;
        }
        else if (s[i] == '-') {
            field += hand[i % n];
            hand[i % n] = 0;
        }
    }
    rep(i, n) cout << hand[i] << "\n";

    return 0;
}
