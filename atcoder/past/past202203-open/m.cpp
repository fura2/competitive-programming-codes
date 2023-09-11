#include "template.hpp"

template<class G>
class Fenwick_tree {
    vector<G> a;

  public:
    Fenwick_tree(int n = 0) {
        build(n);
    }
    Fenwick_tree(const vector<G>& a) {
        build(a);
    }
    void build(int n) {
        a.assign(n, G{});
    }
    void build(const vector<G>& a) {
        this->a = a;
        for (int i = 1; i <= a.size(); i++)
            if (i + (i & -i) <= ssize(a)) (this->a)[i + (i & -i) - 1] += (this->a)[i - 1];
    }
    void add(int i, const G& val) {
        for (i++; i <= ssize(a); i += i & -i) a[i - 1] += val;
    }
    G sum(int l, int r) const {
        if (l == 0) {
            G res{};
            for (; r > 0; r -= r & -r) res += a[r - 1];
            return res;
        }
        return sum(0, r) - sum(0, l);
    }
    int lower_bound(G val) const {
        if (!(G{} < val)) return 0;
        int x = 0, k;
        for (k = 1; k <= ssize(a); k <<= 1)
            ;
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= ssize(a) && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
        return x;
    }
    int upper_bound(G val) const {
        if (val < G{}) return 0;
        int x = 0, k;
        for (k = 1; k <= a.size(); k <<= 1)
            ;
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= a.size() && !(val < a[x + k - 1])) val -= a[x + k - 1], x += k;
        return x;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> P(n);
    rep (i, n) cin >> P[i];
    vector<tuple<int, int, int>> Q(q);
    rep (i, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, x;
            cin >> a >> x;
            a--;
            Q[i] = {type, a, x};
        }
        else {
            int a, x = -1;
            cin >> a;
            a--;
            Q[i] = {type, a, x};
        }
    }

    // compress coordinates
    vector<int> X = P;
    for (auto& [type, a, x]: Q) {
        if (type == 1) {
            X.emplace_back(x);
        }
    }
    sort(all(X));
    X.erase(unique(all(X)), end(X));
    for (auto& p: P) {
        p = lower_bound(all(X), p) - begin(X);
    }
    for (auto& [type, a, x]: Q) {
        if (type == 1) {
            x = lower_bound(all(X), x) - begin(X);
        }
    }

    int m = size(X);
    vector<int> inv(m, -1);
    rep (i, n) {
        inv[P[i]] = i;
    }
    Fenwick_tree<int> F(m);
    for (auto p: P) {
        F.add(p, 1);
    }
    for (auto& [type, a, x]: Q) {
        if (type == 1) {
            inv[P[a]] = -1;
            F.add(P[a], -1);
            P[a] = x;
            inv[P[a]] = a;
            F.add(P[a], 1);
        }
        else if (type == 2) {
            cout << F.sum(P[a], m) << "\n";
        }
        else {
            cout << inv[F.lower_bound(n - a)] + 1 << "\n";
        }
    }

    return 0;
}
