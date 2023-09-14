#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using lint = long long;

int main() {
    lint a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    cout << (a * b + c - d) % k << endl;
    return 0;
}
