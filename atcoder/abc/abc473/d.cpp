#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

int n, k;
vector<int> seq;
vector<vector<int>> ans;

void dfs(int i, int sum) {
  if (i == 1) {
    seq[i - 1] = k - sum;
    ans.emplace_back(seq);
    return;
  }
  for (int x = 0; sum + i * x <= k; x++) {
    seq[i - 1] = x;
    dfs(i - 1, sum + i * x);
  }
}

void testcase() {
  n = input<int>();
  k = input<int>();
  seq.resize(n);
  dfs(n, 0);
  ranges::sort(ans);
  for (auto& a: ans) output(a);
}
