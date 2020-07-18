#include <bits/stdc++.h>

using namespace std;

bool vis[30];

void solve() {
  int n = 0;
  int x;
  cin >> x;
  while ((1LL << n) + n <= x)
    n++;
  n--;
  for (int i = 0; i < 30; ++i)
    vis[i] = 0;
  x -= (1 << n) + n;
  vis[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    if (x >= (1 << i) - 1) {
      x -= (1 << i) - 1;
      vis[i] = 1;
    }
  }
  bool t = 0;
  int sum = 0;
  for (int i = 0; i <= n; ++i) {
    if (vis[i] == 1) {
      if (t == 0) {
        for (int j = 0; j <= i; ++j) {
          cout << i + 1 << ' ' << j + 1 << '\n';
        }
        t = 1;
      } else {
        for (int j = i; j >= 0; --j) {
          cout << i + 1 << ' ' << j + 1 << '\n';
        }
        t = 0;
      }
    } else {
      if (t == 0)
        cout << i + 1 << ' ' << 1 << '\n';
      else
        cout << i + 1 << ' ' << i + 1 << '\n';
    }
  }
  while (x) {
    n++, x--;
    if (t == 0)
      cout << n + 1 << ' ' << 1 << '\n';
    else
      cout << n + 1 << ' ' << n + 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ":\n";
    solve();
  }
}
