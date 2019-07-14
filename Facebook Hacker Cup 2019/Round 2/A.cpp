#include <bits/stdc++.h>

using namespace std;

void solve(int testId) {
	int n, m, k;
	pair<int, int> a[3];
	cin >> n >> m;
	cin >> k;
	for (int i = 0; i < k + 1; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	cout << "Case #" << testId << ": ";
	if (k == 1) {
		cout << "N\n"; return;
	}
	int x = abs(a[0].first + a[0].second - a[1].first - a[1].second);
	int y = abs(a[0].first + a[0].second - a[2].first - a[2].second);
	x %= 2, y %= 2;
	if (x == 0 && y == 0) cout << "Y\n";
	else cout << "N\n";
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
}