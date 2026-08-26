#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();

  map<char, int> hist, cons;
  rep (i, n) {
    ++hist[s[i]];
    if (hist[s[i]] > (n + 1) / 2) {
      output(-1);
      return;
    }
    if (i < n - 1 && s[i] == s[i + 1]) ++cons[s[i]];
  }

  int mx = 0, sum = 0;
  for (auto [k, v]: cons) {
    chmax(mx, v);
    sum += v;
  }
  output(max(mx, (sum + 1) / 2));
}
