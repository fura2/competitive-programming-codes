#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<lint>>(n);

  a.emplace_back(0);
  ranges::sort(a);

  list<lint> L = {-LINF};
  L.append_range(a);
  L.emplace_back(LINF);
  lint ans = 0;

  auto it = L.begin();
  while (*it != 0) ++it;
  rep (_, n) {
    lint cur = *it;
    lint l = *prev(it);
    lint r = *next(it);
    if (cur - l <= r - cur) {
      ans += cur - l;
      it = L.erase(it);
      --it;
    }
    else {
      ans += r - cur;
      it = L.erase(it);
    }
  }
  output(ans);
}
