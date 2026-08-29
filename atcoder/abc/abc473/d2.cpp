#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

int n, k;
vector<int> seq;
vector<vector<int>> ans;

void dfs(int i, int sum) {
  if (i == n - 1) {
    if ((k - sum) % n == 0) {
      seq[i] = (k - sum) / n;
      ans.emplace_back(seq);
    }
    return;
  }
  for (int x = 0; sum + (i + 1) * x <= k; x++) {
    seq[i] = x;
    dfs(i + 1, sum + (i + 1) * x);
  }
}

void testcase() {
  n = input<int>();
  k = input<int>();
  seq.resize(n);
  dfs(0, 0);
  for (auto& a: ans) output(a);
}
