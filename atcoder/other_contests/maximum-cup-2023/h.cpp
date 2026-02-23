#include "template.hpp"

bool vis[61][11][2];
string memo[61][11][2];

string dfs(int i, bool larger, const string &s, int m) {
    if (i == 61) {
        return (m == 0 and larger ? "" : "2");
    }

    if (vis[i][m][larger]) return memo[i][m][larger];
    vis[i][m][larger] = true;

    string &res = memo[i][m][larger];
    res = "2";
    // put 0
    if (larger or s[i] == '0') {
        string t = dfs(i + 1, larger, s, m);
        if (t != "2") chmin(res, "0" + t);
    }
    // put 1
    if (m > 0) {
        string t = dfs(i + 1, larger or s[i] == '0', s, m - 1);
        if (t != "2") chmin(res, "1" + t);
    }
    return res;
}

string f(string s, int m) {
    memset(vis, 0, sizeof vis);
    return dfs(0, false, s, m);
}

int main() {
    int n;
    lint x;
    cin >> n >> x;
    vector<int> M(n);
    rep (i, n) cin >> M[i];

    string s(61, '?');
    rep (i, 61) s[60 - i] = bit(x, i) + '0';

    rep (i, n) {
        string s_next = s;
        rep (m, 1, M[i] + 1) chmax(s_next, f(s, m));
        s = s_next;
    }

    lint ans = 0;
    rep (i, 61) {
        if (s[i] == '1') ans += 1LL << (60 - i);
    }
    cout << ans << endl;

    return 0;
}
