#include "template.hpp"

using Real = double;

constexpr Real EPS = 1e-8;

int sgn(const Real& x) { return x > EPS ? 1 : x < -EPS ? -1 : 0; }

class point {
public:
    Real x, y;
    point() {}
    point(const Real& x, const Real& y):x(x), y(y) {}
    point& operator+=(const point& p) { x += p.x; y += p.y; return *this; }
    point& operator-=(const point& p) { x -= p.x; y -= p.y; return *this; }
    point& operator*=(const Real& c) { x *= c; y *= c; return *this; }
    point& operator/=(const Real& c) { x /= c; y /= c; return *this; }
    point operator+(const point& p)const { return point(*this) += p; }
    point operator-(const point& p)const { return point(*this) -= p; }
    point operator*(const Real& c)const { return point(*this) *= c; }
    point operator/(const Real& c)const { return point(*this) /= c; }
    point operator-()const { return point(-x, -y); }

    friend point operator*(const Real& c, const point& p) { return p * c; }
};

Real dot(const point& p, const point& q) { return p.x * q.x + p.y * q.y; }
Real cross(const point& p, const point& q) { return p.x * q.y - p.y * q.x; }

class line {
public:
    point a, b;
    line() {}
    line(const point& a, const point& b):a(a), b(b) {}
};

enum { CCW = 1, CW = -1, ON = 0 };
int ccw(const point& a, const point& b, const point& c) {
    int d = sgn(cross(b - a, c - a));
    return d > 0 ? CCW : d < 0 ? CW : ON;
}

int main() {
    int n, k; cin >> n >> k;
    point s, t;
    cin >> s.x >> s.y >> t.x >> t.y;

    vector<lint> cost(n);
    rep(i, n) {
        double a, b, c;
        cin >> a >> b >> c >> cost[i];

        line l;
        if (a != 0) {
            l = { point(c / a, 0), point((c - b) / a, 1) };
        }
        else {
            l = { point(0, c / b), point(1, (c - a) / b) };
        }
        if (ccw(l.a, l.b, s) == ccw(l.a, l.b, t)) {
            cost[i] = 0;
        }
    }

    sort(all(cost));
    while (ssize(cost) > k) cost.pop_back();
    cout << accumulate(all(cost), 0LL) << endl;

    return 0;
}
