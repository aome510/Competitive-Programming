#include <bits/stdc++.h>

using namespace std;

long long resL, resR, resPtr;
const long long MX = sqrt(2e18) + 5;

void calc(long long L, long long R, long long ptr) {
  long long mx = max(L, R);
  long long mn = min(L, R);
  long long gap = mx - mn;
  if (gap < ptr) {
    int parity = ptr & 1;
    long long low, high, start;
    start = ptr / 2;
    low = start - 1, high = MX;
    while (low < high) {
      long long mid = (low + high + 1) / 2;
      long long sum = (mid + start + parity) * (mid - start + 1);
      if (sum <= mx)
        low = mid;
      else
        high = mid - 1;
    }
    long long ptrMx = low;
    long long sumMx = (low + start + parity) * (low - start + 1);

    start = ptr / 2 + parity;
    low = start - 1, high = MX;
    while (low < high) {
      long long mid = (low + high + 1) / 2;
      long long sum = (mid + start + 1 - parity) * (mid - start + 1);
      if (sum <= mn)
        low = mid;
      else
        high = mid - 1;
    }
    long long ptrMn = low;
    long long sumMn = (low + start + 1 - parity) * (low - start + 1);

    if (L == mx) {
      resL = L - sumMx, resR = R - sumMn;
    } else {
      resR = R - sumMx, resL = L - sumMn;
    }
    resPtr = max(ptrMx * 2 + parity, ptrMn * 2 + 1 - parity);
  } else {
    long long low = ptr, high = MX;
    while (low < high) {
      long long mid = (low + high + 1) / 2;
      long long sum = (mid + ptr) * (mid - ptr + 1) / 2;
      if (gap >= sum)
        low = mid;
      else
        high = mid - 1;
    }
    long long sum = (low + ptr) * (low - ptr + 1) / 2;
    if (L > R)
      L -= sum;
    else
      R -= sum;
    calc(L, R, low + 1);
  }
}

void solve() {
  long long L, R;
  cin >> L >> R;
  calc(L, R, 1);
  cout << resPtr << ' ' << resL << ' ' << resR << '\n';
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
