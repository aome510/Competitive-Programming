#include <bits/stdc++.h>

using namespace std;

bool check(int n, int m, long long a) {
    for (int i = 1; i < n; ++i) {
        if (a > 1LL * i * m && (a - 1LL * i * m) % (n - i) == 0) return 1;
        if (a % (n - i) == 0 && a / (n - i) <= m) return 1;
    }
    return 0;
}

int main() {
    int n, m;
    long long a;
    while (cin >> n >> m >> a) {
        if (a % n == 0 || a % m == 0) {
            cout << 1 << '\n'; continue;
        }
        if (check(n, m, a) || check(m, n, a)) {
            cout << 2 << '\n'; continue;
        }
        cout << 3 << '\n';
    }
}
