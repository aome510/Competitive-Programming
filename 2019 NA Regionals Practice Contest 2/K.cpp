#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int n, m, s, d;
int a[N];
int b[N];
int f[N][N];

void upd(int &a, int b) { a = max(a, b); }

void solve() {
    for (int i = 0; i < s; ++i) cin >> a[i];
    memset(f, -INF, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j <= n; ++j) {
            upd(f[i + 1][j], f[i][j] + a[i]);
            upd(f[i + 1][min(n, j + d - a[i])], f[i][j]);
        }
    }
    if (f[s][n] < m) {
        cout << "impossible\n"; return;
    }
    int cur = n;
    for (int i = s - 1; i >= 0; --i) {
        if (f[i + 1][cur] == f[i][cur] + a[i]) continue; 
        for (int j = 0; j <= n; ++j) {
            if (min(n, j + d - a[i]) == cur && f[i + 1][cur] == f[i][j]) {
                b[i] = cur - j, cur = j; break;
            }
        }
    }
    for (int i = 0; i < s; ++i) cout << b[i] << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m >> s >> d) solve();
}
