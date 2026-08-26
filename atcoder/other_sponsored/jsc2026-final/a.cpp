#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();

  map<char, int> hist, cons;
  rep (i, n) {
    ++hist[s[i]];
    if (i < n - 1 && s[i] == s[i + 1]) ++cons[s[i]];
  }

  for (auto [k, v]: hist) {
    if (v > (n + 1) / 2) {
      output(-1);
      return;
    }
  }

  int ans = 0;
  priority_queue<int> Q;
  for (auto [k, v]: cons) Q.emplace(v);
  while (!Q.empty()) {
    if (Q.size() == 1) {
      ans += Q.top();
      Q.pop();
    }
    else {
      int x = Q.top();
      Q.pop();
      int y = Q.top();
      Q.pop();
      ans++;
      x--;
      y--;
      if (x > 0) Q.emplace(x);
      if (y > 0) Q.emplace(y);
    }
  }
  output(ans);
}
