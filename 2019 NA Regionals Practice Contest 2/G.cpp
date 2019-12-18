#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, k;
    while (cin >> n >> m >> k) {
        long long cur = 0;
        if (n > m * (k - 1)) {
            long long tmp = (n - m * (k - 1) + k - 1) / k;
            /* cout << tmp << '\n'; */
            cur += n * tmp - k * tmp * (tmp - 1) / 2;
            n -= k * tmp;
        }
        /* cout << cur << ' ' << n << '\n'; */
        long long mx = 0;
        while (n > 0) {
            long long a = n / m;
            long long b = a + 1;
            long long cntb = n % m;
            long long cnta = m - cntb;
             // cout << a << ' ' << b << ' ' << cnta << ' ' << cntb << ' ' << cur << '\n'; 
            long long tmp = cur;
            tmp += n * cntb - b * (cntb - 1) * cntb / 2;
            long long N = n - cntb * b;
            tmp += N * cnta - a * cnta * (cnta - 1) / 2;
            mx = max(mx, tmp);
            cur += n, n -= k;
        }
        mx = max(mx, cur);
        /* mx = max(mx, cur + n * (n + 1) / 2); */
        cout << mx << '\n';
    }
}
