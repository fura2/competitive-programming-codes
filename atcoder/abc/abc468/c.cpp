#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  auto p = input<vector<int>>(n, 1);
  auto q = input<vector<int>>(n, 1);

  int ans = 0;
  while (ranges::next_permutation(p).found) {
    if (p >= q) break;
    ans++;
  }
  output(ans);
}
