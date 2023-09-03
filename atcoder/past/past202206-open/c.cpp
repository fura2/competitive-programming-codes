#include "template.hpp"

int main() {
    lint n, m;
    cin >> n >> m;

    string ans;
    lint pw = 1;
    rep (i, m) {
        if (pw <= lint(1e9)) pw *= n;
        ans += (pw <= lint(1e9) ? 'o' : 'x');
    }
    cout << ans << endl;

    return 0;
}
