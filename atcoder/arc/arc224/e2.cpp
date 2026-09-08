#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();

  int ans = 0;
  vector<char> S;
  for (char c: s) {
    if (c == 'A') {
      S.emplace_back(c);
    }
    else if (c == 'B') {
      while (!S.empty() && S.back() != 'A') {
        S.pop_back();
        S.pop_back();
      }
      if (S.empty()) {
        ans++;
      }
      else {  // S.back() == 'A'
        S.emplace_back(c);
      }
    }
    else {  // c == 'C'
      while (!S.empty() && S.back() != 'B') {
        S.pop_back();
      }
      if (S.empty()) {
        ans++;
      }
      else {  // S.back() == 'B'
        S.pop_back();
        S.pop_back();
      }
    }
  }
  output(ans);
}
