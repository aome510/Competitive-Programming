#include <bits/stdc++.h>

using namespace std;


int n;
long long a[1000005];
double res;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
	for (int i = 1; i <= n; ++i) {
		res = max(res, max(1.0 * a[i] / i, 1.0 * (a[n] - a[i - 1]) / (n - i + 1)));
	}
	cout << fixed << setprecision(9) << res;
}