#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "data_structure/addable_heap.hpp"
#include "template/main.hpp"

void testcase() {
  auto q = input<int>();
  lint v = input<lint>();

  AddableMaxHeap<lint> Q;
  lint pre = 0;
  rep (_, q) {
    auto type = input<int>();
    auto t = input<lint>();

    Q.add_all(t - pre);
    if (type == 1) {
      Q.push(input<lint>());
    }
    else {
      if (Q.empty()) {
        output(-1);
      }
      else {
        output(min(Q.top(), v));
        Q.pop();
      }
    }
    pre = t;
  }
}
