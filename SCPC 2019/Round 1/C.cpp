#include <bits/stdc++.h>

using namespace std;

const int lim = 5e5;
const int LG = 20;

int f[lim + 5];
int g[lim + 5];
int lg2[lim + 5];
int trace[lim + 5];
int rmq[LG][lim + 5];

int find(long long x) {
	int l = 1, r = lim;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (1LL * mid * (mid + 1) / 2 <= x) l = mid; else r = mid - 1;
	}
	return l;
}

int get(int l, int r) {
	int k = lg2[r - l + 1];
	return max(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}

void prep() {
	for (int i = 1; i <= lim; ++i) {
		f[i] = 1e9;
		for (int k = 1; k * (k + 1) / 2 <= i; ++k) {
			f[i] = min(f[i], f[i - k * (k + 1) / 2] + k);
			if (f[i] == f[i - k * (k + 1) / 2] + k) trace[i] = k;
		}
		if (trace[i - 1] > trace[i]) cout << i << ' ';
		rmq[0][i] = f[i];
	}	
	for (int i = 2; i <= lim; ++i) lg2[i] = lg2[i >> 1] + 1;
	for (int i = 1; i < LG; ++i) {
		for (int j = 0; j + (1 << i) - 1 <= lim; ++j) {
			rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int calc(long long l, long long r, int x) {
	if (r <= lim) return get(l, r);
	long long X = 1LL * x * (x + 1) / 2;
	int res = 1e9;
	if (r >= X && r - X <= lim) {
		if (l >= X) {
			res = x + calc(l - X, r - X, x);
		}
		else {
			res = max(x + calc(0, r - X, x), calc(l, X - 1, x - 1));
		}
	}
	if (x > 1) res = min(res, calc(l, r, x - 1));
	return res;
}

void solve(int idTest) {
	long long l, r; cin >> l >> r;
	cout << "Case #" << idTest << '\n' << calc(l, r, lim) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	prep();
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}