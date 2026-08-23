#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

template <class T>
vector<pair<T, int>> run_length_encoding(const vector<T>& a) {
  vector<pair<T, int>> res;
  int n = a.size(), pre = 0;
  rep (i, n)
    if (i == n - 1 || a[i] != a[i + 1])
      res.emplace_back(a[i], i - pre + 1), pre = i + 1;
  return res;
}

void testcase() {
  // vector<bool> a(1 << 10);
  // a[0] = false;
  // rep (S, 1 << 10) {
  //   if (S == 0) continue;

  //   a[S] = false;
  //   rep (T, S) {
  //     if ((T & S) != T) continue;
  //     bool ok = true;
  //     rep (i, 9) {
  //       if (bit(S - T, i) && bit(S - T, i + 1)) ok = false;
  //     }
  //     if (!ok) continue;
  //     if (!a[T]) a[S] = true;
  //   }
  // }

  // rep (i, 9) show(i, a[(1 << i) - 1]);

  auto n = input<int>();
  auto a = input<vector<int>>(n);
  bool win = false;
  for (auto [x, c]: run_length_encoding(a)) {
    if (x == 0) continue;
    if (c != 2) win = true;
  }
  output(win ? "Alice" : "Bob");
}
