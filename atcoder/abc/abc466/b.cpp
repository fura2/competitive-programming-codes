#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int m = input<int>();
  vector<int> a(m, -1);
  rep (i, n) {
    int c = input<int>() - 1;
    int s = input<int>();
    chmax(a[c], s);
  }
  output(a);
}
