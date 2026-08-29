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
  rep (i, n - 1) {
    vector<mint> f(2);
    f[0] = 1;
    f[1] = n - i - 1;
    Q.emplace(f);
  }
  Q.push(vector<mint>{1});
  Q.push(vector<mint>{1});
  while (Q.size() >= 2) {
    auto f = Q.top();
    Q.pop();
    auto g = Q.top();
    Q.pop();
    auto p = convolution(f, g);
    if (p.size() > k - n + 1) {
      p.resize(k - n + 1);
    }
    Q.emplace(p);
  }
  auto p = Q.top();

  mint denom = 1;
  rep (i, n) denom *= i + 1;

  output((p[k - n] / denom).val());
}
