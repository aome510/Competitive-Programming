#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; vector<int> vec;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x, vec.push_back(x);
  }
  int res = 0;
  for (int i = 0; i < (n - 1); ++i) {
    auto j = min_element(vec.begin() + i, vec.end());
    // cout << i << ": " << j - vec.begin() << '\n';
    reverse(vec.begin() + i, j + 1);
    res += j - (vec.begin() + i) + 1;
  }
  cout << res << '\n';
}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
