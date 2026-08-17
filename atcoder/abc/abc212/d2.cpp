#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "data_structure/addable_heap.hpp"
#include "template/main.hpp"

void testcase() {
  auto q = input<int>();
  AddableMinHeap<lint> Q;
  rep (_, q) {
    auto t = input<int>();
    if (t == 1) {
      Q.push(input<lint>());
    }
    else if (t == 2) {
      Q.add_all(input<lint>());
    }
    else {
      output(Q.top());
      Q.pop();
    }
  }
}
