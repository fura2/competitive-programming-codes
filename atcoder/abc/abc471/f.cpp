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

  vector<string> t(n);  // leading zeros trimmed
  vector<int> d(n);
  rep (i, n) {
    t[i] = trim(s[i]);
    d[i] = t[i].empty() ? INF : s[i].size() - t[i].size();
  }

  // Case 1: 先頭を top k 以外から選ぶ
  string ans = "";
  if (k < n) {
    int i_max = k;
    rep (i, k + 1, n) {
      if (cmp(t[i_max], t[i])) i_max = i;
    }

    vector<string> r(s.begin(), s.begin() + k - 1);
    ranges::sort(r, [](const auto& a, const auto& b) { return a + b > b + a; });

    ans = trim(s[i_max] + ranges::fold_left(r, "", plus{}));
  }

  // Case 2: 先頭を top k から選ぶ
  vector<int> C;  // candidates of the head
  int d_min = *min_element(d.begin(), d.begin() + k);
  rep (i, k) {
    if (d[i] == d_min) {
      if (C.empty() || t[C[0]].starts_with(t[i]) || t[i].starts_with(t[C[0]])) {
        bool same = false;
        for (int j: C)
          if (t[i] == t[j]) same = true;
        if (!same) C.emplace_back(i);
      }
      else if (t[C[0]] < t[i]) {
        C = {i};
      }
    }
  }

  vector<int> p(k);
  ranges::iota(p, 0);
  ranges::sort(p, [&](int i, int j) { return s[i] + s[j] > s[j] + s[i]; });
  for (int i0: C) {
    string res = s[i0];
    for (int i: p) {
      if (i != i0) res += s[i];
    }
    res = trim(res);
    if (cmp(ans, res)) ans = res;
  }

  output(ans);
}
