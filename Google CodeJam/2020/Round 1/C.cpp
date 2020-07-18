#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[105][105];
bool dead[1005][1005];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
  cin >> n >> m;
  if (n * m > 100)
    return;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      dead[i][j] = 0;
      sum += a[i][j];
    }
  }
  while (1) {
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dead[i][j])
          continue;
        int cnt2 = 0;
        int sum2 = 0;
        for (int k = 0; k < 4; ++k) {
          int ti = i, tj = j;
          while (1) {
            ti += dx[k], tj += dy[k];
            if (ti < 0 || tj < 0 || ti >= n || tj >= m)
              break;
            if (dead[ti][tj])
              continue;
            sum2 += a[ti][tj], cnt2++;
            break;
          }
        }
        if (cnt2 * a[i][j] < sum2) {
          vec.push_back({i, j});
        }
      }
    }
    if (!vec.size())
      break;
    for (auto x : vec)
      dead[x.first][x.second] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!dead[i][j])
          sum += a[i][j];
      }
    }
  }
  cout << sum << '\n';
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
