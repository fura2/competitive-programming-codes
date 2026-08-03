#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto a = input<vector<int>>(3);
  ranges::sort(a, greater());
  cout << a[0] << a[1] << a[2] << endl;
}
