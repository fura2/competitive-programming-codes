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
      if (S.empty() || (!S.empty() && S.back() == 'B')) {
        while (!S.empty() && S.back() == 'B') {
          S.pop_back();
          S.pop_back();
        }
        if (!S.empty()) {
          S.emplace_back(c);
        }
        else {
          ans++;
        }
      }
      else {  // S.back() == 'A'
        S.emplace_back(c);
      }
    }
    else {  // c=='C'
      if (S.empty()) {
        ans++;
      }
      else if (S.back() == 'B') {
        S.pop_back();
        S.pop_back();
      }
      else {  // S.back() == 'A'
        while (!S.empty() && S.back() == 'A') S.pop_back();
        if (!S.empty() && S.back() == 'B') {
          S.pop_back();
          S.pop_back();
        }
        else {
          ans++;
        }
      }
    }
  }
  output(ans);
}
