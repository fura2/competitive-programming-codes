#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/isqrt.hpp"

void testcase() {
  auto n = input<lint>();
  output(isqrt(n / 2) + isqrt(n / 4));
}
