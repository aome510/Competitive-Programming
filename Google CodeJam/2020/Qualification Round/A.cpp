#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N][N];
bool vis[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  int trace = 0;
  for (int i = 1; i <= n; ++i)
    trace += a[i][i];
  int cntRow = 0, cntCol = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      vis[j] = 0;
    for (int j = 1; j <= n; ++j) {
      if (vis[a[i][j]]) {
        cntRow++;
        break;
      }
      vis[a[i][j]] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      vis[j] = 0;
    for (int j = 1; j <= n; ++j) {
      if (vis[a[j][i]]) {
        cntCol++;
        break;
      }
      vis[a[j][i]] = 1;
    }
  }
  cout << trace << ' ' << cntRow << ' ' << cntCol << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
