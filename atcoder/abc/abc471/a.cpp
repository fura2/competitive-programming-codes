#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto a = input<int>();
  auto b = input<int>();
  output(a + b == 9 || a - b == 9 || a * b == 9 || a == b * 9 ? "Nine"
                                                              : "Nein");
}
