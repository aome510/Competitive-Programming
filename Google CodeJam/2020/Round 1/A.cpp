#include <bits/stdc++.h>

using namespace std;

void solve() {
  string pref, suff;
  string midd;
  string s;
  vector<string> vpref, vsuff;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    string tmp;
    vector<string> vec;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == '*') {
        if (tmp.size()) {
          vec.push_back(tmp);
          tmp.clear();
        }
        vec.push_back("*");
      } else {
        tmp.push_back(s[j]);
      }
    }
    if (tmp.size()) {
      vec.push_back(tmp);
      tmp.clear();
    }
    vpref.push_back(vec[0]);
    vsuff.push_back(vec.back());
    if (vec[0] != "*") {
      if (pref.size() < vec[0].size())
        pref = vec[0];
    }
    if (vec.back() != "*") {
      if (suff.size() < vec.back().size())
        suff = vec.back();
    }
    for (int j = 1; j + 1 < vec.size(); ++j) {
      if (vec[j] != "*")
        midd += vec[j];
    }
  }
  bool fail = 0;
  reverse(suff.begin(), suff.end());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < vpref[i].size(); ++j) {
      if (vpref[i][j] == '*')
        break;
      if (vpref[i][j] != pref[j]) {
        fail = 1;
        break;
      }
    }
    reverse(vsuff[i].begin(), vsuff[i].end());
    for (int j = 0; j < vsuff[i].size(); ++j) {
      if (vsuff[i][j] == '*')
        break;
      if (vsuff[i][j] != suff[j]) {
        fail = 1;
        break;
      }
    }
  }
  reverse(suff.begin(), suff.end());
  if (fail)
    cout << "*\n";
  else
    cout << pref << midd << suff << '\n';
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
