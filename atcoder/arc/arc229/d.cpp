#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto k = input<lint>();
  auto a = input<vector<lint>>(k + 1);

  lint sum = accumulate(a.begin(), a.end(), 0LL);
  lint mn = ranges::min(a);

  if (mn % k == 0) {
    lint d = mn / k;
    if (sum - (k + 1) * d * k >= k) {
      output("Alice");
    }
    else {
      output("Bob");
    }
    return;
  }
  output("Alice");
}
