#include <bits/stdc++.h>

using namespace std;

class ThreeNeighbors {
public:
  vector<string> construct(int N) {
    vector<string> res;
    string s0;
    for (int i = 0; i < 50; ++i)
      s0 += 'X';
    while (N) {
      if (N == 1) {
        string s1 = s0;
        s1[0] = '.';
        res.push_back(s0);
        res.push_back(s1);
        N--;
      } else {
        int tmp = min(N / 2, 48);
        string s1;
        for (int i = 0; i <= tmp + 1; ++i)
          s1 += '.';
        while (s1.size() < 50)
          s1 += 'X';
        res.push_back(s0);
        res.push_back(s1);
        res.push_back(s1);
        res.push_back(s0);
        N -= tmp * 2;
      }
    }
    return res;
  }
} test;

// int main() {
//   int N;
//   cin >> N;
//   vector<string> res = test.construct(N);
//   cout << res.size() << '\n';
//   for (auto s : res)
//     cout << s << '\n';
// }
