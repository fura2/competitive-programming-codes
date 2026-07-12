#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

int n;
vector<lint> a;
map<lint, lint> memo[200000];

lint f(int i, lint x) {
  if (a[n - 1] > x) return 1;

  i = ranges::lower_bound(a, x, greater()) - a.begin();

  if (i == n - 1) return x / a[i] + 1;

  if (memo[i].contains(x)) return memo[i][x];

  return memo[i][x] = (x / a[i]) * f(i + 1, a[i] - 1) + f(i + 1, x % a[i]);
}

void testcase() {
  n = input<int>();
  auto x = input<lint>();
  a.clear();
  rep (i, n) {
    auto b = input<lint>();
    if (a.empty() || a.back() > b) a.emplace_back(b);
  }
  n = a.size();

  rep (i, n) memo[i].clear();
  output(f(0, x) - 1);
}
