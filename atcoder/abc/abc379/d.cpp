#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "data_structure/addable_heap.hpp"
#include "template/main.hpp"

void testcase() {
  auto q = input<int>();
  AddableMaxHeap<lint> Q;
  rep (_, q) {
    auto type = input<int>();
    if (type == 1) {
      Q.push(0);
    }
    else if (type == 2) {
      auto t = input<lint>();
      Q.add_all(t);
    }
    else {
      auto h = input<lint>();
      int ans = 0;
      while (!Q.empty() && Q.top() >= h) {
        Q.pop();
        ans++;
      }
      output(ans);
    }
  }
}
