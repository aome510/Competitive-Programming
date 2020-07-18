#include <bits/stdc++.h>

using namespace std;

class FixedNumberOfDigits {
public:
  int countDigits(long long x) {
    if (x == 0)
      return 1;
    int ret = 0;
    while (x) {
      x /= 10, ret++;
    }
    return ret;
  };
  long long sum(int start, int step, long long nDigits) {
    int currentDigits = countDigits(start);
    long long cur = start;
    while (nDigits) {
      // cout << cur << '\n';
      long long low = 0, high = 1e16;
      while (low < high) {
        long long mid = (low + high) >> 1;
        long long tmp = cur + mid * step;
        if (countDigits(tmp) > currentDigits ||
            nDigits <= (mid + 1) * currentDigits) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
      if (countDigits(cur + low * step) > currentDigits)
        low--;
      if (nDigits > (low + 1) * currentDigits) {
        nDigits -= (low + 1) * currentDigits;
        cur += step * (low + 1);
        currentDigits = countDigits(cur);
      } else {
        assert(nDigits > low * currentDigits);
        nDigits -= low * currentDigits;
        cur += step * low;
        vector<int> digits;
        if (cur == 0)
          return 0;
        while (cur)
          digits.push_back(cur % 10), cur /= 10;
        reverse(digits.begin(), digits.end());
        long long res = 0;
        for (int i = 0; i < nDigits; i++)
          res = res * 10 + digits[i];
        return res;
      }
    }
    assert(0);
  }
} test;

// int main() {
//   int start, step;
//   long long nDigits;
//   cin >> start >> step >> nDigits;
//   cout << test.sum(start, step, nDigits);
// }
