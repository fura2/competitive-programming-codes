#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  for (char& c: s)
    if (c != 'A') c = '.';
  output(s);
}
