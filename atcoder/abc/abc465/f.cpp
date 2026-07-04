#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  vector<string> s(n);
  vector<lint> a(n);
  rep (i, n) {
    s[i] = input<string>();
    a[i] = input<lint>();
  }

  static lint cum[11][11][11][11][11][11];
  rep (i, n) {
    cum[s[i][0] - '0' + 1][s[i][1] - '0' + 1][s[i][2] - '0' + 1]
       [s[i][3] - '0' + 1][s[i][4] - '0' + 1][s[i][5] - '0' + 1] += a[i];
  }
  rep (i0, 11)
    rep (i1, 11)
      rep (i2, 11)
        rep (i3, 11)
          rep (i4, 11)
            rep (i5, 10)
              cum[i0][i1][i2][i3][i4][i5 + 1] += cum[i0][i1][i2][i3][i4][i5];
  rep (i0, 11)
    rep (i1, 11)
      rep (i2, 11)
        rep (i3, 11)
          rep (i4, 10)
            rep (i5, 11)
              cum[i0][i1][i2][i3][i4 + 1][i5] += cum[i0][i1][i2][i3][i4][i5];
  rep (i0, 11)
    rep (i1, 11)
      rep (i2, 11)
        rep (i3, 10)
          rep (i4, 11)
            rep (i5, 11)
              cum[i0][i1][i2][i3 + 1][i4][i5] += cum[i0][i1][i2][i3][i4][i5];
  rep (i0, 11)
    rep (i1, 11)
      rep (i2, 10)
        rep (i3, 11)
          rep (i4, 11)
            rep (i5, 11)
              cum[i0][i1][i2 + 1][i3][i4][i5] += cum[i0][i1][i2][i3][i4][i5];
  rep (i0, 11)
    rep (i1, 10)
      rep (i2, 11)
        rep (i3, 11)
          rep (i4, 11)
            rep (i5, 11)
              cum[i0][i1 + 1][i2][i3][i4][i5] += cum[i0][i1][i2][i3][i4][i5];
  rep (i0, 10)
    rep (i1, 11)
      rep (i2, 11)
        rep (i3, 11)
          rep (i4, 11)
            rep (i5, 11)
              cum[i0 + 1][i1][i2][i3][i4][i5] += cum[i0][i1][i2][i3][i4][i5];

  int q = input<int>();
  rep (_, q) {
    auto x = input<string>();
    auto y = input<string>();

    bool ok = true;
    rep (i, 6)
      if (x[i] > y[i]) ok = false;
    if (!ok) {
      output(0);
      continue;
    }

    lint ans = 0;
    rep (S, 1 << 6) {
      int sgn = (popcount(unsigned(S)) % 2 == 0 ? 1 : -1);
      int i[6];
      rep (j, 6) i[j] = (bit(S, j) ? x[j] - '0' : y[j] - '0' + 1);
      ans += sgn * cum[i[0]][i[1]][i[2]][i[3]][i[4]][i[5]];
    }
    output(ans);
  }
}
