#include <bits/stdc++.h>

using namespace std;

int n;
int a[105];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n, greater<int>());
	double sum = 0;
	double res = 0;
	for (int i = 0; i < n; ++i) {
		sum += 0.01 * a[i];
		res = max(res, pow(sum, 1 / sum));
	}
	cout << fixed << setprecision(6) << res;
}