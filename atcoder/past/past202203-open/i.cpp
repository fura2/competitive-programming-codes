#include "template.hpp"

bool f(vector<pair<int, int>> P, vector<pair<int, int>> Q) {
    int n = size(P);
    rep (i, n) P[i].first *= -1;

    int x_min = 1e9;
    rep (i, n) chmin(x_min, P[i].first);
    rep (i, n) P[i].first -= x_min;
    x_min = 1e9;
    rep (i, n) chmin(x_min, Q[i].first);
    rep (i, n) Q[i].first -= x_min;

    return set(all(P)) == set(all(Q));
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> P(n), Q(n);
    for (auto& [x, y]: P) cin >> x >> y;
    for (auto& [x, y]: Q) cin >> x >> y;

    if (set(all(P)) == set(all(Q)) or f(P, Q)) {
        yes();
        return 0;
    }
    rep (i, n) {
        swap(P[i].first, P[i].second);
        swap(Q[i].first, Q[i].second);
    }
    yesno(f(P, Q));

    return 0;
}
