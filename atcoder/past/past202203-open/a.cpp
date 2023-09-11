#include "template.hpp"

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    set<int> S;
    S.emplace(a * b);
    S.emplace(a * c);
    S.emplace(b * c);
    cout << *begin(S) << " " << *prev(end(S)) << endl;

    return 0;
}
