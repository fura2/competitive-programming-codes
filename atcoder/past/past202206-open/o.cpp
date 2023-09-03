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
            if (i + (i & -i) <= a.size()) (this->a)[i + (i & -i) - 1] += (this->a)[i - 1];
    }
    void add(int i, const G& val) {
        for (i++; i <= int(a.size()); i += i & -i) a[i - 1] += val;
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
        for (k = 1; k <= a.size(); k <<= 1)
            ;
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= a.size() && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
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

class mint {
    static const int MOD = 998244353;
    int x;

  public:
    mint(): x(0) {}
    mint(long long y) {
        x = y % MOD;
        if (x < 0) x += MOD;
    }

    mint& operator+=(const mint& m) {
        x += m.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& m) {
        x -= m.x;
        if (x < 0) x += MOD;
        return *this;
    }
    mint& operator*=(const mint& m) {
        x = (long long)x * m.x % MOD;
        return *this;
    }
    mint& operator/=(const mint& m) {
        return *this *= inverse(m);
    }
    mint operator+(const mint& m) const {
        return mint(*this) += m;
    }
    mint operator-(const mint& m) const {
        return mint(*this) -= m;
    }
    mint operator*(const mint& m) const {
        return mint(*this) *= m;
    }
    mint operator/(const mint& m) const {
        return mint(*this) /= m;
    }
    mint operator-() const {
        return -x;
    }

    friend mint inverse(const mint& m) {
        int a = m.x, b = MOD, u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return u;
    }

    friend istream& operator>>(istream& is, mint& m) {
        long long t;
        is >> t;
        m = t;
        return is;
    }
    friend ostream& operator<<(ostream& os, const mint& m) {
        return os << m.x;
    }
    int to_int() const {
        return x;
    }
};

mint operator+(long long x, const mint& m) {
    return mint(x) + m;
}
mint operator-(long long x, const mint& m) {
    return mint(x) - m;
}
mint operator*(long long x, const mint& m) {
    return mint(x) * m;
}
mint operator/(long long x, const mint& m) {
    return mint(x) / m;
}

struct Point {
    lint x, y;
    Point operator-() const {
        return {-this->x, -this->y};
    }
    bool operator==(const Point& p) const {
        return this->x == p.x and this->y == p.y;
    }
    bool operator!=(const Point& p) const {
        return not(*this == p);
    }
};

lint cross(const Point& p, const Point& q) {
    return p.x * q.y - p.y * q.x;
}

int quadrant(const Point& p) {
    if (p.x > 0 and p.y >= 0) return 0;
    if (p.y > 0 and p.x <= 0) return 1;
    if (p.x < 0 and p.y <= 0) return 2;
    return 3;
}

int main() {
    int n;
    cin >> n;
    vector<char> Op(n);
    vector<Point> P(n);
    rep (i, n) cin >> Op[i] >> P[i].x >> P[i].y;

    P.resize(2 * n);
    rep (i, n) P[i + n] = -P[i]; // antipodal points

    vector<int> Ord(2 * n);
    iota(all(Ord), 0);
    sort(all(Ord), [&](int i, int j) { // argument sort, tie break by index
        int qi = quadrant(P[i]);
        int qj = quadrant(P[j]);
        if (qi != qj) return qi < qj;
        lint c = cross(P[i], P[j]);
        if (c != 0) return c > 0;
        return i < j;
    });

    vector<int> Inv(2 * n);
    rep (t, 2 * n) Inv[Ord[t]] = t;

    mint ans = 0;
    Fenwick_tree<mint> Fx(4 * n), Fy(4 * n);
    rep (i, n) {
        int t = Inv[i];
        int t_ap = Inv[i + n]; // order of the antipodal point of P[i]
        if (t_ap < t) t_ap += 2 * n;
        mint sum_x_pos = Fx.sum(t, t_ap);
        mint sum_y_pos = Fy.sum(t, t_ap);
        mint sum_x_neg = Fx.sum(t, t + 2 * n) - sum_x_pos;
        mint sum_y_neg = Fy.sum(t, t + 2 * n) - sum_y_pos;

        if (Op[i] == '+') {
            ans += P[i].x * sum_y_pos - P[i].y * sum_x_pos;
            ans -= P[i].x * sum_y_neg - P[i].y * sum_x_neg;
            Fx.add(t, P[i].x);
            Fx.add(t + 2 * n, P[i].x);
            Fy.add(t, P[i].y);
            Fy.add(t + 2 * n, P[i].y);
        }
        else { // '-'
            Fx.add(t, -P[i].x);
            Fx.add(t + 2 * n, -P[i].x);
            Fy.add(t, -P[i].y);
            Fy.add(t + 2 * n, -P[i].y);
            ans -= P[i].x * sum_y_pos - P[i].y * sum_x_pos;
            ans += P[i].x * sum_y_neg - P[i].y * sum_x_neg;
        }
        cout << ans << "\n";
    }

    return 0;
}
