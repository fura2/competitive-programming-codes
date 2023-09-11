#include "template.hpp"

int main() {
    int t, n;
    cin >> t >> n;
    vector<int> mx(n);
    rep (t) {
        rep (i, n) {
            int c;
            cin >> c;
            chmax(mx[i], c);
        }
        cout << accumulate(all(mx), 0) << "\n";
    }

    return 0;
}
