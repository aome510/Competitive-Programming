#include <bits/stdc++.h>

using namespace std;

const int N = 4005;

int n, m;
int sz[N];
int par[N];
bool f[N][N];
bool s[N];

int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}

void solve(int testId) {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) par[i] = i, sz[i] = 0;
	for (int i = 1; i <= m; ++i) {
		int x, y; cin >> x >> y;
		for (int j = 0; j < (y - x + 1) / 2; ++j) {
			par[find(x + j)] = find(y - j);
		}
	}
	for (int i = 1; i <= n; ++i) sz[find(i)]++;
	vector< pair<int, int> > vec;
	for (int i = 1; i <= n; ++i) {
		if (find(i) == i) vec.push_back({i, sz[i]});
	}

	int sz = vec.size(), sum = 0;
	f[0][0] = 1;
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j <= n; ++j) f[i + 1][j] = 0;
		for (int j = 0; j <= sum; ++j) {
			f[i + 1][j] |= f[i][j];
			f[i + 1][j + vec[i].second] |= f[i][j];
		}
		sum += vec[i].second;
	}

	int res = n, opt = 0;
	for (int i = 0; i <= n; ++i) {
		if (f[sz][i] && res > abs(i - (n - i))) {
			res = abs(i - (n - i)), opt = i;
		}
	}

	for (int i = sz - 1; i >= 0; --i) {
		if (f[i][opt]) {
			s[vec[i].first] = 0;
		}
		else {
			s[vec[i].first] = 1, opt -= vec[i].second;
		}
	}
	for (int i = 1; i <= n; ++i) s[i] = s[find(i)];
	
	// cout << res << '\n';
	cout << "Case #" << testId << ": ";
	for (int i = 1; i <= n; ++i) cout << s[i];
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
}