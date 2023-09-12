#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    int t, a, b;
    scanf("%d%d%d", &t, &a, &b);

    if (max(a, b) > t) {
        puts("NO");
        return 0;
    }
    if (a == 0 && b == 0 && t == 1) {
        puts("NO");
        return 0;
    }

    vector<string> ops;
    int x = 0, y = 0;
    while (pair(x, y) != pair(b, a)) {
        string op;
        if (x < b) op += '>', x++;
        if (y < a) op += '^', y++;
        ops.emplace_back(op);
    }
    if (ops.empty()) {
        ops.emplace_back("^");
        ops.emplace_back("v");
    }

    while (ssize(ops) < t) {
        string op = ops.back();
        ops.pop_back();
        if (ssize(op) == 2) {
            ops.emplace_back(op.substr(0, 1));
            ops.emplace_back(op.substr(1));
        }
        else { // ssize(op) == 1
            if (op == "<" or op == ">") {
                ops.emplace_back(op + "^");
                ops.emplace_back("v");
            }
            else { // op == "^" or op == "v"
                ops.emplace_back(op + "<");
                ops.emplace_back(">");
            }
        }
    }

    puts("YES");
    for (const auto& op: ops) puts(op.c_str());

    return 0;
}
