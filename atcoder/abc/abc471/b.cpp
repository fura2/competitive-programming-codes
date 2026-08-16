#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  map<string, int> h;
  rep (_, n) {
    auto s = input<string>();
    for (char& c: s) c = toupper(c);
    ++h[s];
  }

  int mx = 0;
  for (auto [k, v]: h) chmax(mx, v);
  output(mx);
}
