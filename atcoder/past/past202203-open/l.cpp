#include "template.hpp"

lint mod;

struct monoid {
    lint val, ten; // ten = 10^n mod MOD (n は val の桁数)

    monoid(): val(0), ten(1) {}
    monoid(lint val, lint ten): val(val), ten(ten) {}
    monoid operator*(const monoid& x) const { // val の文字列としての連結
        return {(val * x.ten + x.val) % mod, ten * x.ten % mod};
    }
};

template<class M>
M pow(M f, long long k) {
    M res;
    for (; k > 0; k >>= 1) {
        if (k & 1) res = res * f;
        f = f * f;
    }
    return res;
}

int main() {
    lint k;
    cin >> k >> mod;

    monoid ans;
    rep (k) {
        lint c, d;
        cin >> c >> d;
        ans = ans * pow(monoid{c, 10}, d);
    }
    cout << ans.val << endl;

    return 0;
}
