#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "typical/knapsack_01.hpp"

void testcase() {
  auto n = input<int>();
  auto W = input<lint>();
  vector<lint> v(n), w(n);
  rep (i, n) {
    v[i] = input<lint>();
    w[i] = input<lint>();
  }

  lint res;
  if (n <= 30) {
    res = knapsack_01(w, v, W, KnapsackAlgorithm::MeetInTheMiddle);
  }
  else if (ranges::max(w) <= 1000) {
    res = knapsack_01(w, v, W, KnapsackAlgorithm::WeightDp);
  }
  else {
    res = knapsack_01(w, v, W, KnapsackAlgorithm::ValueDp);
  }
  output(res);
}
