#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    vector<long> a(n);
    for (auto& e : a) cin >> e;

    set<int> Idx;
    rep(i, n) Idx.emplace(i);
    set<pair<long, int>> S;
    rep(i, n) S.emplace(-a[i], i);

    long ans = 0;
    rep(_, (n + 1) / 2) {
        int i = S.begin()->second;

        ans += a[i];
        if (i == *Idx.begin()) {
            S.erase({ -a[i], i });
            Idx.erase(i);
            if (!S.empty()) {
                int r = *Idx.upper_bound(i);
                S.erase({ -a[r], r });
                Idx.erase(r);
            }
        }
        else if (i == *Idx.rbegin()) {
            S.erase({ -a[i], i });
            Idx.erase(i);
            if (!S.empty()) {
                int l = *--Idx.lower_bound(i);
                S.erase({ -a[l], l });
                Idx.erase(l);
            }
        }
        else {
            int l = *--Idx.lower_bound(i);
            int r = *Idx.upper_bound(i);
            S.erase({ -a[i], i });
            S.erase({ -a[l], l });
            S.erase({ -a[r], r });
            Idx.erase(l);
            Idx.erase(r);
            a[i] = a[l] + a[r] - a[i];
            S.emplace(-a[i], i);
        }
        cout << ans << endl;
    }

    return 0;
}
