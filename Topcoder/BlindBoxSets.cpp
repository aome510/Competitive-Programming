#include <bits/stdc++.h>

using namespace std;

class BlindBoxSets {
public:
  static const int N = 55;

  double f[N][N][N][N];

  void upd(double &x, double y) { x += y; }

  double expectedPurchases(int numSets, int numItems) {
    int s[5];
    for (s[1] = 0; s[1] <= numItems; ++s[1]) {
      for (s[2] = 0; s[2] <= numItems - s[1]; ++s[2]) {
        for (s[3] = 0; s[3] <= numItems - s[1] - s[2]; ++s[3]) {
          for (s[4] = 0; s[4] <= numItems - s[1] - s[2] - s[3]; ++s[4]) {
            s[0] = numItems - s[1] - s[2] - s[3] - s[4];
            int n = numItems - s[numSets];
            if (n == 0)
              continue;

            double cur = f[s[1]][s[2]][s[3]][s[4]] + 1;
            upd(f[s[1] + 1][s[2]][s[3]][s[4]], cur * s[0] / n);
            upd(f[s[1]][s[2] + 1][s[3]][s[4]], cur * s[1] / n);
            upd(f[s[1]][s[2]][s[3] + 1][s[4]], cur * s[2] / n);
            upd(f[s[1]][s[2]][s[3]][s[4] + 1], cur * s[3] / n);
          }
        }
      }
    }

    switch (numSets) {
    case 1:
      return f[numItems][0][0][0];
    case 2:
      return f[0][numItems][0][0];
    case 3:
      return f[0][0][numItems][0];
    case 4:
      return f[0][0][0][numItems];
    default:
      assert(0);
    }
  }
} test;

int main() {
  int numSets, numItems;
  cin >> numSets >> numItems;
  cout << test.expectedPurchases(numSets, numItems);
}
