#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  auto s = input<string>();

  deque<int> D;
  bool dir = true;
  rep (i, n) {
    if (dir)
      D.emplace_back(i + 1);
    else
      D.push_front(i + 1);
    if (s[i] == 'o') dir = !dir;
  }
  if (!dir) ranges::reverse(D);

  vector<int> ans(from_range, D);
  output(ans);
}
