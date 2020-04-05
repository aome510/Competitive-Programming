#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  string res;
  int cntOpen = 0;
  for (auto c : s) {
    int x = c - '0';
    while (x > cntOpen) {
      cntOpen++;
      res += '(';
    }
    while (x < cntOpen) {
      cntOpen--;
      res += ')';
    }
    res += c;
  }
  while (cntOpen) {
    res += ')';
    cntOpen--;
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
