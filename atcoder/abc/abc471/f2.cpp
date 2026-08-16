#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

bool cmp(const string& s, const string& t) {
  if (s.size() != t.size()) return s.size() < t.size();
  return s < t;
}

string trim(const string& s) {
  int n = s.size();
  for (int i = 0; i < n; ++i)
    if (s[i] != '0') return s.substr(i);
  return "";
}

void testcase() {
  auto n = input<int>(), k = input<int>();
  auto s = input<vector<string>>(n);

  bool zero = true;
  rep (i, n) {
    if (ranges::count(s[i], '0') != s[i].size()) zero = false;
  }
  if (zero) {
    output(0);
    return;
  }

  ranges::sort(s, [](const auto& a, const auto& b) { return cmp(b, a); });

  // Case 1: 先頭を top k 以外から選ぶ
  string ans1 = "";
  if (k < n) {
    int i_max = k;
    rep (i, k + 1, n) {
      if (stoll(s[i_max]) < stoll(s[i])) i_max = i;
    }

    vector<string> r(s.begin(), s.begin() + k - 1);
    r.emplace_back(s[i_max]);
    ranges::sort(r, [](const auto& a, const auto& b) { return a + b > b + a; });

    ans1 = trim(accumulate(r.begin(), r.end(), ""s));
  }

  // Case 2: 先頭を top k から選ぶ
  sort(s.begin(), s.begin() + k, [](const auto& a, const auto& b) {
    return a + b > b + a;
  });
  string ans2 = trim(accumulate(s.begin(), s.begin() + k, ""s));

  output(cmp(ans1, ans2) ? ans2 : ans1);
}
