#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

bool ask(int i, int j) {
  if (i == j) return true;
  cout << "? " << i + 1 << " " << j + 1 << endl;
  string s;
  cin >> s;
  return s == "Yes";
}

void testcase() {
  int n;
  cin >> n;

  int ans = 0;
  int r = 1;
  rep (l, n) {
    while (r < n) {
      if (!ask(l, r)) break;
      r++;
    }
    ans += r - l - 1;
  }
  cout << "! " << ans << endl;
}
