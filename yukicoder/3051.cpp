#include <cstdio>
#include <string>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using lint = long long;

constexpr int SIZE = 1065;

constexpr lint MOD = 998244353;
constexpr lint BASE = 126 - 32 + 1;
lint BASE_POW[SIZE];

lint rolling_hash(const string& s) {
    lint h = 0;
    rep (i, SIZE) {
        if (32 <= s[i] and s[i] <= 126) {
            h = (h + BASE_POW[SIZE - i - 1] * (s[i] - 32)) % MOD;
        }
    }
    return h;
}

int main() {
    BASE_POW[0] = 1;
    rep (i, SIZE - 1) BASE_POW[i + 1] = BASE_POW[i] * BASE % MOD;

    string s;
    rep (_, SIZE) s += getchar();

    lint h = rolling_hash(s);
    rep (i, SIZE) {
        if (32 <= s[i] and s[i] <= 126) {
            for (char c = 32; c <= 126; c++) {
                lint h2 = (h + BASE_POW[SIZE - i - 1] * (c - s[i])) % MOD;
                if (h2 < 0) h2 += MOD;
                if (h2 == 0) {
                    printf("%d\n\"%c\"\n\"%c\"\n", i, c, s[i]);
                    return 0;
                }
            }
        }
    }

    return 0;
}
// $?Q<D