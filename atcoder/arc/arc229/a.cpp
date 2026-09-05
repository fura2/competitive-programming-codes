#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

vector<int> f(int x) {
  vector<int> seq(25, 1);
  while (x > 0) {
    seq.insert(seq.begin() + min(x, 25), 0);
    x -= min(x, 25);
  }
  return seq;
}

void testcase() {
  auto x = input<int>();

  auto seq = f(x);
  string ans = "";
  for (int b: seq) {
    ans += "CA"[b];
    ans += "R";
  }
  ans.pop_back();
  output(ans);
}
