#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int f[N];
long long sum[N];

int main() {
	for (int i = 2; i <= 1000000; ++i) {
		f[i] = f[(i + 1) / 2] + 1 + (i % 2);
		sum[i] = sum[i - 1] + f[i]; 
	}
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		int l, r; cin >> l >> r;
		cout << "Case #" << i << '\n';
		cout << sum[r] - sum[l - 1] << '\n';
	}
}