#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto q = input<int>();

  vector<int> a(n);
  int x = 0;
  set<int> S;  // non-zeros
  rep (_, q) {
    int t = input<int>();
    if (t == 1) {
      int i = input<int>() - 1;
      if (a[i] == 0) S.emplace(i);
      x ^= a[i] ^ (a[i] + 1);
      a[i]++;
    }
    else {
      for (auto it = S.begin(); it != S.end();) {
        int i = *it;
        x ^= a[i] ^ (a[i] - 1);
        a[i]--;
        if (a[i] == 0)
          it = S.erase(it);
        else
          ++it;
      }
    }
    output(x);
  }
}
