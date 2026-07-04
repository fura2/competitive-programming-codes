#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

vector<lint> f(lint x, lint k) {
  vector<lint> v;
  while (x > 0) {
    v.emplace_back(x % k);
    x /= k;
  }
  ranges::reverse(v);
  return v;
}

void testcase() {
  lint x = input<lint>();
  lint y = input<lint>();
  lint k = input<lint>();

  vector<lint> v1 = f(x, k), v2 = f(y, k);

  int c = 0;
  rep (i, min(v1.size(), v2.size())) {
    if (v1[i] != v2[i]) break;
    c++;
  }
  output(v1.size() + v2.size() - 2 * c);
}
