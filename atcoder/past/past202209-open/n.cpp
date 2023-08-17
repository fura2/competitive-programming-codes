#include "template.hpp"

string f(const vector<string> &B0, const vector<tuple<int, int, char>> &Q) {
    int h = size(B0);
    vector<deque<char>> B(h);
    rep(i, h) {
        B[i] = deque<char>(all(B0[i]));
    }

    string res;
    for (auto &&[t, p, c] : Q) {
        if (t == 1) {
            res += B[p].back();
            B[p].pop_back();
            B[p].push_front(c);
        } else {
            res += B[h - 1][p];
            rrep(i, h - 1) B[i + 1][p] = B[i][p];
            B[0][p] = c;
        }
    }
    return res;
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<string> B(h);
    rep(i, h) cin >> B[i];
    vector<tuple<int, int, char>> Q(q);
    for (auto &[t, p, c] : Q) {
        cin >> t >> p >> c;
        p--;
    }

    if (h > w) { // transpose
        vector B2(w, string(h, '?'));
        rep(i, h) rep(j, w) B2[j][i] = B[i][j];
        for (auto &[t, p, c] : Q) {
            t = 3 - t;
        }
        B = B2;
    }

    cout << f(B, Q) << endl;

    return 0;
}
