#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

vector<lint> a;
unordered_map<lint, lint> memo;

lint f(lint x) {
  int i = ranges::lower_bound(a, x, greater()) - a.begin();
  if (i == a.size()) return 1;

  if (memo.contains(x)) return memo[x];
  return memo[x] = (x / a[i]) * f(a[i] - 1) + f(x % a[i]);
}

void testcase() {
  auto n = input<int>();
  auto x = input<lint>();
  a.clear();
  rep (i, n) {
    auto e = input<lint>();
    if (a.empty() || a.back() > e) a.emplace_back(e);
  }

  memo.clear();
  output(f(x) - 1);
}
