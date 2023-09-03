#include "template.hpp"

int main() {
    string s;
    cin >> s;
    int n = s.size();

    map<string, int> H;
    rep (i, n - 1) ++H[s.substr(i, 2)];

    cout << max_element(all(H), [](const auto& x, const auto& y) { return x.second < y.second; })
                ->first
         << endl;

    return 0;
}
