#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "typical/knapsack_01.hpp"

void testcase() {
  auto n = input<int>();
  vector<int> w(n);
  vector<lint> a(n), b(n);
  rep (i, n) {
    w[i] = input<int>();
    a[i] = input<lint>();
    b[i] = input<lint>();
  }

  int wsum = reduce(w.begin(), w.end());
  lint bsum = reduce(b.begin(), b.end());
  vector<int> W(n);
  vector<lint> V(n);
  rep (i, n) {
    W[i] = 2 * w[i];
    V[i] = a[i] - b[i];
  }
  output(bsum + knapsack_01(W, V, wsum, KnapsackAlgorithm::WeightDp));
}
