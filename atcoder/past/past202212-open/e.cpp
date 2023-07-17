#include "template.hpp"

int main() {
    string s; cin >> s;
    int n = s.size();
    int cnt = 0;
    rep(i, n) {
        if (s[i] == '(') cnt++;
        else {
            cnt--;
            if (cnt < 0) {
                no();
                return 0;
            }
        }
    }
    yesno(cnt == 0);

    return 0;
}
