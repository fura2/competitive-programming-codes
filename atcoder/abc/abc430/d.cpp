#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  set<lint> S = {-LINF, 0, LINF};

  auto cost = [&](lint x) {
    auto r = S.upper_bound(x);
    auto l = prev(r, 2);
    return min(x - *l, *r - x);
  };

  lint ans = cost(0);
  rep (_, n) {
    auto x = input<lint>();
    auto r = S.upper_bound(x);
    auto l = prev(r, 1);
    if (*l > -LINF) ans -= cost(*l);
    if (*r < LINF) ans -= cost(*r);

    S.emplace(x);
    ans += cost(x);
    if (*l > -LINF) ans += cost(*l);
    if (*r < LINF) ans += cost(*r);

    output(ans);
  }
}
