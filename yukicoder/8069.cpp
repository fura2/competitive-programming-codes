#include "template.hpp"

int main() {
    int r, c;
    string s;
    cin >> r >> c >> s;

    // delete redundant moves (e.g., LRLRLR -> R)
    {
        int f[128];
        f['U'] = f['D'] = 0;
        f['L'] = f['R'] = 1;

        string t;
        for (char c: s) {
            if (not t.empty() and f[t.back()] == f[c]) {
                t.pop_back();
            }
            t += c;
        }
        s = t;
    }
    int n = size(s);

    if (count(all(s), 'U') == 0 or count(all(s), 'L') == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (s.substr(n - 2) == "DR" or s.substr(n - 2) == "RD") {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> ans;
    int idx = min(s.find_last_of('U'), s.find_last_of('L'));
    ans.emplace_back(r, c + 1);
    ans.emplace_back(r + 1, c);
    if (s[idx] == 'U') {
        ans.emplace_back(r - 1, c);
        ans.emplace_back(r + 1, 1);
        ans.emplace_back(r + 2, 0);
        ans.emplace_back(0, 1);
    }
    else { // s[idx] == 'L'
        ans.emplace_back(r, c - 1);
        ans.emplace_back(1, c + 1);
        ans.emplace_back(0, c + 2);
        ans.emplace_back(1, 0);
    }
    sort(all(ans));
    ans.erase(unique(all(ans)), end(ans));

    cout << size(ans) << "\n";
    for (auto [x, y]: ans) {
        cout << x << " " << y << "\n";
    }

    return 0;
}
