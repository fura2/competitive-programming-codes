#include "template/template.hpp"

#include <utility>

// #define MULTI_TESTCASE
#include "algebra/monoid_impl.hpp"
#include "data_structure/segment_tree.hpp"
#include "template/main.hpp"

using MinMonoidWithId = MonoidImpl<pair<lint, int>,
                                   [](const auto& a, const auto& b) {
                                     return (b.first < a.first) ? b : a;
                                   },
                                   []() { return pair{LINF, -1}; }>;

void testcase() {
  auto n = input<int>();
  auto p = input<vector<int>>(n, 1);
  auto a = input<vector<lint>>(n);

  // pos[i] = (j < i かつ p[j] > p[i] なる最大の j (なければ 0))
  vector<int> pos(n);
  {
    stack<int> S;
    rep (i, n) {
      while (!S.empty() && p[S.top()] < p[i]) {
        S.pop();
      }
      if (!S.empty()) pos[i] = S.top();
      S.emplace(i);
    }
  }

  vector<int> cnt(n);
  SegmentTree<MinMonoidWithId> S(n);
  S.set(0, pair{a[p[0]], 0});

  lint ans = 0;
  rep (i, 1, n) {
    auto [val, par] = S.fold(pos[i], n).unwrap();
    ans += val;
    cnt[par]++;
    S.set(par, pair{a[p[par]] * (2 * cnt[par] + 1), par});
    S.set(i, pair{a[p[i]], i});
  }
  output(ans);
}
