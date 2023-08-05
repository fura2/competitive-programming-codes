// アルファベットを 0, 1, ..., 25 で読み替えて, mod 26 で考える.
// A の先頭に 0 を追加して
//   A = (A_0 = 0, A_1, A_2, ..., A_N).
// 差分を取って
//   D = (D_1, D_2, ..., D_N), D_i = A_i - A_{i-1}.
// 操作 (L, R) は D_L += 1, D_{R+1} -= 1 に対応する.

// N が偶数のとき, 特に N = 6 の例を考える. (N が奇数でも同様)
// 回文の条件は
//   A_1 = A_6, A_2 = A_5, A_3 = A_4.
// これを D で書き直すと
//   D_2 + D_3 + ... + D_6 = 0, D_3 + D_4 + D_5 = 0, D_4 = 0.
// 整理すると
//   D_2 + D_6 = 0, D_3 + D_5 = 0, D_4 = 0.
// E_1 = D_2 + D_6, E_2 = D_3 + D_5, E_3 = D_4 とグループ分けすると, 操作は
//   (1) E_i を 1 増やし, E_j を 1 減らす
//   (2) E_i を 1 増やすか減らす
//   (3) 何もしない
// の 3 種類に分類できる.
// 各 E_i に対応する頂点 i を作り, その頂点に E_i 個の石を置く.
// 操作 (1) に対して, 頂点 i と j の間に辺を張ると, この操作は石を辺に沿って自由に動かせることに相当する.
// 操作 (2) は, 頂点 i に追加で好きなだけ石を置けることに相当する.
// よって, グラフの連結成分に含まれる石の数を数えることで答えが判定できる.

#include "template.hpp"

class mint {
    static const int MOD = 26;
    int x;
public:
    mint():x(0) {}
    mint(long long y) { x = y % MOD; if (x < 0) x += MOD; }

    mint& operator+=(const mint& m) { x += m.x; if (x >= MOD) x -= MOD; return *this; }
    mint& operator-=(const mint& m) { x -= m.x; if (x < 0) x += MOD; return *this; }
    mint& operator*=(const mint& m) { x = (long long)x * m.x % MOD; return *this; }
    mint& operator/=(const mint& m) { return *this *= inverse(m); }
    mint operator+(const mint& m)const { return mint(*this) += m; }
    mint operator-(const mint& m)const { return mint(*this) -= m; }
    mint operator*(const mint& m)const { return mint(*this) *= m; }
    mint operator/(const mint& m)const { return mint(*this) /= m; }
    mint operator-()const { return -x; }

    friend mint inverse(const mint& m) {
        int a = m.x, b = MOD, u = 1, v = 0;
        while (b > 0) { int t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        return u;
    }

    friend istream& operator>>(istream& is, mint& m) { long long t; is >> t; m = t; return is; }
    friend ostream& operator<<(ostream& os, const mint& m) { return os << m.x; }
    int to_int()const { return x; }
};

mint operator+(long long x, const mint& m) { return mint(x) + m; }
mint operator-(long long x, const mint& m) { return mint(x) - m; }
mint operator*(long long x, const mint& m) { return mint(x) * m; }
mint operator/(long long x, const mint& m) { return mint(x) / m; }

class union_find {
    int n;
    vector<int> p;
public:
    union_find(int n = 0) { build(n); }
    void build(int n) {
        this->n = n;
        p.assign(n, -1);
    }
    int find(int u) { return p[u] < 0 ? u : p[u] = find(p[u]); }
    void unite(int u, int v) {
        u = find(u); v = find(v);
        if (u != v) {
            if (p[v] < p[u]) swap(u, v);
            p[u] += p[v]; p[v] = u; n--;
        }
    }
    bool is_same(int u, int v) { return find(u) == find(v); }
    int size()const { return n; }
    int size(int u) { return -p[find(u)]; }
};

int main() {
    string s;
    int m; cin >> s >> m;
    vector<int> L(m), R(m);
    rep(j, m) cin >> L[j] >> R[j];

    int n = s.size();
    vector<mint> A(n + 1);
    rep(i, n) A[i + 1] = s[i] - 'a';

    vector<mint> D(n + 1); // D_i = A_i - A_{i-1}
    rep(i, n) D[i + 1] = A[i + 1] - A[i];

    vector<mint> V;
    vector<int> f(n + 2, -1); // index of D -> index of V
    if (n % 2 == 0) {
        rep(i, n / 2 - 1) {
            f[i + 2] = f[n - i] = V.size();
            V.emplace_back(D[i + 2] + D[n - i]);
        }
        f[n / 2 + 1] = V.size();
        V.emplace_back(D[n / 2 + 1]);
    }
    else {
        rep(i, n / 2) {
            f[i + 2] = f[n - i] = V.size();
            V.emplace_back(D[i + 2] + D[n - i]);
        }
    }

    int N = V.size();
    vector<bool> good(N); // 自由に値を決められる頂点

    union_find U(N);
    rep(j, m) {
        int l = L[j], r = R[j] + 1;
        if (f[l] != -1 && f[r] != -1 && f[l] != f[r]) {
            U.unite(f[l], f[r]);
        }
        else if (f[l] != -1 && f[r] == -1) {
            good[f[l]] = true;
        }
        else if (f[l] == -1 && f[r] != -1) {
            good[f[r]] = true;
        }
    }
    rep(u, N) if (good[u]) good[U.find(u)] = true;

    vector<mint> sum(N); // representative -> sum of V
    rep(u, N) sum[U.find(u)] += V[u];

    rep(u, N) {
        int r = U.find(u);
        if (r != u) continue;
        if (good[r]) continue;
        if (sum[r].to_int() != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
