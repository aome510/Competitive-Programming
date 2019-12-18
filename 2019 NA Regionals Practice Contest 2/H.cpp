#include <bits/stdc++.h>

using namespace std;

int n, a[55];

int main() {
    while (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mn = 1e9, pos = -1;
    for (int i = 0; i + 2 < n; ++i) {
        if (mn > max(a[i], a[i + 2])) {
            mn = max(a[i], a[i + 2]), pos = i + 1;
        }
    }
    cout << pos << ' ' << mn << '\n';
    }
}
