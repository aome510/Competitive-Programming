#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int id[N], st[N], ed[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) id[i] = i, cin >> st[i] >> ed[i];
  sort(id, id + n, [] (int a, int b) {
    return ed[a] < ed[b];
  });
  int edC = 0, edJ = 0;
  string res(n, 'C');
  for (int i = 0; i < n; ++i) {
    int j = id[i];
    if (edJ > st[j] && edC > st[j]) {
      cout << "IMPOSSIBLE\n"; return;
    } else if (edJ <= st[j] && (edJ > edC || edC > st[j])) {
      edJ = ed[j], res[j] = 'J';
    } else {
      edC = ed[j];
    }
  }
  cout << res << '\n';
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
