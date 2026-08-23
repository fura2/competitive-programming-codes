#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"
#include "typical/run_length_encoding.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);
  bool win = false;
  for (auto [x, c]: run_length_encoding(a)) {
    if (x == 1 && c != 2) win = true;
  }
  output(win ? "Alice" : "Bob");
}
