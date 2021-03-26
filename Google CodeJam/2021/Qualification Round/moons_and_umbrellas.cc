#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6;

void solve() {
  int x, y; string s;
  cin >> x >> y >> s;
  int f[2];
  f[0] = f[1] = 0;
  // 0 for C, 1 for J
  // CJ pays X, JC pays Y
  for (auto i : s) {
    int g[2];
    if (i == '?') {
      g[0] = min(f[0], f[1] + y);
      g[1] = min(f[1], f[0] + x);
    } else if (i == 'C') {
      g[0] = min(f[0], f[1] + y);
      g[1] = INF;
    } else {
      g[0] = INF;
      g[1] = min(f[1], f[0] + x);
    }
    swap(f, g);
  }
  cout << min(f[0], f[1]) << '\n';
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
