#include <bits/stdc++.h>

#define _overload4(a, b, c, d, e, ...) e
#define _overload5(a, b, c, d, e, f, ...) f
#define _rep1(n) for (int _ = 0; _ < (n); ++_)
#define _rep2(i, n) for (int i = 0; i < (n); ++i)
#define _rep3(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep4(i, a, b, c) for (int i = (a); i < (b); i+=(c))
#define rep(...) _overload4(__VA_ARGS__, _rep4, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define _show1(a) { std::clog << #a << " = " << a << endl; }
#define _show2(a, ...) { std::clog << #a << " = " << a << ", "; _show1(__VA_ARGS__); }
#define _show3(a, ...) { std::clog << #a << " = " << a << ", "; _show2(__VA_ARGS__); }
#define _show4(a, ...) { std::clog << #a << " = " << a << ", "; _show3(__VA_ARGS__); }
#define _show5(a, ...) { std::clog << #a << " = " << a << ", "; _show4(__VA_ARGS__); }
#define show(...) _overload5(__VA_ARGS__, _show5, _show4, _show3, _show2, _show1)(__VA_ARGS__)

template<typename T>
constexpr inline int bit(T x, unsigned int k) { return (x >> k) & 1; }

template<typename C>
long ssize(const C& c) { return std::size(c); }  // workaround until C++20

void yes() { std::cout << "Yes\n"; }
void no() { std::cout << "No\n"; }
void yesno(bool b) { std::cout << (b ? "Yes" : "No") << "\n"; }

template<class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e : v) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "]";
    return os;
}

struct Setup {
    Setup() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(11);
    }
} _setup;

using namespace std;

class Node {
public:
    Node* l;
    Node* r;
    int cnt;  // subtree size
    int val;
    Node():l(nullptr), r(nullptr), cnt(0), val(-1) {}
};

multiset<int> S;

int find_val(Node* u, int dep) {
    if (u->l) return find_val(u->l, dep + 1);
    if (u->r) return find_val(u->r, dep + 1);
    return u->val;
}

void add(Node* u, int x, int dep = 0) {
    u->cnt++;

    if (dep == 30) {
        u->val = x;
        if (u->cnt >= 2) {
            S.emplace(0);
        }
        return;
    }

    int xor_pre = -1;
    if (u->cnt == 3 && u->l && u->r && u->l->cnt == 1 && u->r->cnt == 1) {
        int vl = find_val(u->l, dep + 1);
        int vr = find_val(u->r, dep + 1);
        xor_pre = vl ^ vr;
    }

    int b = bit(x, 29 - dep);
    if (b == 0) {
        if (!u->l) u->l = new Node();
        add(u->l, x, dep + 1);
    }
    else {
        if (!u->r) u->r = new Node();
        add(u->r, x, dep + 1);
    }

    if (u->cnt == 2 && u->l && u->r && u->l->cnt == 1 && u->r->cnt == 1) {
        int vl = find_val(u->l, dep + 1);
        int vr = find_val(u->r, dep + 1);
        S.emplace(vl ^ vr);
    }
    if (xor_pre != -1) {
        S.erase(S.find(xor_pre));
    }
}

void erase(Node* u, int x, int dep = 0) {
    u->cnt--;

    if (dep == 30) {
        if (u->cnt >= 1) {
            S.erase(S.find(0));
        }
        return;
    }

    int xor_pre = -1;
    if (u->cnt == 1 && u->l && u->r && u->l->cnt == 1 && u->r->cnt == 1) {
        int vl = find_val(u->l, dep + 1);
        int vr = find_val(u->r, dep + 1);
        xor_pre = vl ^ vr;
    }

    int b = bit(x, 29 - dep);
    if (b == 0) {
        erase(u->l, x, dep + 1);
        if (u->l->cnt == 0) {
            delete u->l;
            u->l = nullptr;
        }
    }
    else {
        erase(u->r, x, dep + 1);
        if (u->r->cnt == 0) {
            delete u->r;
            u->r = nullptr;
        }
    }

    if (u->cnt == 2 && u->l && u->r && u->l->cnt == 1 && u->r->cnt == 1) {
        int vl = find_val(u->l, dep + 1);
        int vr = find_val(u->r, dep + 1);
        S.emplace(vl ^ vr);
    }
    if (xor_pre != -1) {
        S.erase(S.find(xor_pre));
    }
}

int main() {
    Node root;

    int q; cin >> q;
    rep(q) {
        int type; cin >> type;
        if (type == 1) {
            int x; cin >> x;
            add(&root, x);
        }
        else if (type == 2) {
            int x; cin >> x;
            erase(&root, x);
        }
        else {
            cout << *S.begin() << "\n";
        }
    }
    return 0;
}
