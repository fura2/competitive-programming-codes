#include "template/template.hpp"

// #define MULTI_TESTCASE
#include <atcoder/all>

#include "template/main.hpp"

using namespace atcoder;

using mint = modint998244353;

void testcase() {
  auto n = input<int>();
  auto k = input<lint>();

  if (k >= 2 * n) {
    output(0);
    return;
  }

  priority_queue<vector<mint>,
                 vector<vector<mint>>,
                 decltype([](const auto& f, const auto& g) {
                   return f.size() > g.size();
                 })>
      Q;
  Q.push({1});
  rep (i, n - 1) {
    Q.push({1, n - i - 1});
  }
  while (Q.size() >= 2) {
    auto f = Q.top();
    Q.pop();
    auto g = Q.top();
    Q.pop();
    auto p = convolution(f, g);
    if (p.size() > k - n + 1) {
      p.resize(k - n + 1);
    }
    Q.push(std::move(p));
  }
  auto p = Q.top();

  mint denom = 1;
  rep (i, n) denom *= i + 1;

  output((p[k - n] / denom).val());
}
