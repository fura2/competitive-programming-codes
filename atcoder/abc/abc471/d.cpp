#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto q = input<int>();
  lint v = input<lint>();

  priority_queue<lint> Q;
  lint ofs = 0;
  lint pre = 0;
  rep (_, q) {
    auto type = input<int>();
    auto t = input<lint>();
    ofs += t - pre;
    if (type == 1) {
      auto w = input<lint>();
      Q.emplace(w - ofs);
    }
    else {
      if (Q.empty()) {
        output(-1);
      }
      else {
        lint x = Q.top();
        Q.pop();
        output(min(x + ofs, v));
      }
    }
    pre = t;
  }
}
