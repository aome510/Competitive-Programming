#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, c;
  cin >> n >> c;
  vector<int> vec(n);
  vector<int> cnt(n);
  for (int i = 0; i < n; ++i) vec[i] = i + 1;
  for (int i = 0; i < (n - 1); ++i) cnt[i] = 1, c--;
  for (int i = (n - 2); i >= 0; --i) {
    if (c <= 0) break;
    int tmp = min(c, n-1-i);
    c -= tmp;
    reverse(vec.begin()+i, vec.begin()+i+tmp+1);
  }
  if (c != 0) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for (auto i: vec) cout << i << " ";
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
