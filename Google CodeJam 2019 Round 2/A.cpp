#include <bits/stdc++.h>

using namespace std;

const int N = 305;

int n;
pair<int, int> a[N];
map< pair<int, int>, bool> mp;

void solve(int testId) {
	cin >> n; mp.clear();
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			int difx = a[i].first - a[j].first;
			int dify = a[i].second - a[j].second;
			if (difx > 0 && dify < 0 || difx < 0 && dify > 0) {
				difx = abs(difx), dify = abs(dify);
				int gcd = __gcd(difx, dify);
				difx /= gcd, dify /= gcd;
				mp[{difx, dify}]++;
			}
		}
	}
	cout << "Case #" << testId << ": " << mp.size() + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}