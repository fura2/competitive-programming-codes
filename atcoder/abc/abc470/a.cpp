#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  rep (i, 1, n + 1) {
    output(i % 3 == 0 ? "Fizz" : to_string(i));
  }
}
