#include "template/template.hpp"

#define MULTI_TESTCASE
#include "graph/graph.hpp"
#include "graph/odd_cycle.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto G = input<Graph>(n, m, 1);

  auto C = odd_cycle(G);
  if (C.empty()) {
    output(-1);
  }
  else {
    output(C.size());
    for (auto e: C) output(e.from + 1);
  }
}
