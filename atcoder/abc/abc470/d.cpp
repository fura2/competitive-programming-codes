#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/permutation.hpp"

void testcase() {
  auto n = input<int>();
  auto q = input<int>();
  auto p = Permutation{input<vector<int>>(n, 1)};

  rep (_, q) {
    auto t = input<int>();
    if (t == 1) {
      auto i = input<int>() - 1;
      auto j = input<int>() - 1;
      p.swap(i, j);
    }
    else {
      p.invert();
    }
  }
  output(p.unwrap(), 1);
}
