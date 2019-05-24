#include <bits/stdc++.h>

using namespace std;

const int N = 305;

int n;
pair<int, int> a[N];
pair<int, int> mn, mx;

pair<int, int> Min(pair<int, int> x, pair<int, int> y) {
	if (1LL * x.first * y.second <= 1LL * x.second * y.first) return x;
	else return y;
}

pair<int, int> Max(pair<int, int> x, pair<int, int> y) {
	if (1LL * x.first * y.second >= 1LL * x.second * y.first) return x;
	else return y;
}

int f(int x) {
	long long L = 1LL * x * mn.first / mn.second;
	long long R = (1LL * x * mx.first + mx.second - 1) / mx.second;
	if (L + 1 < R) return L + 1;
	return -1;  
}

void solve(int testId) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	mn = {0, 1}, mx = {1e9, 1};
	for (int i = 0; i + 1 < n; ++i) {
		int dx = a[i + 1].first - a[i].first;
		int dy = a[i + 1].second - a[i].second;
		if (dx < 0 && dy > 0) {
			mn = Max(mn, {-dx, dy});
		}
		else if (dx > 0 && dy < 0) {
			mx = Min(mx, {dx, -dy});
		}
		else if (dx <= 0 && dy <= 0) {
			cout << "Case #" << testId << ": " << "IMPOSSIBLE\n";
			return;
		}
	}
	if (1LL * mn.first * mx.second >= 1LL * mn.second * mx.first) {
		cout << "Case #" << testId << ": " << "IMPOSSIBLE\n";
	}
	else {
		int l = 1, r = 1e9;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (f(mid) != -1) r = mid; else l = mid + 1;
		}
		int res = l, sz = 1e5;
		for (int i = max(1, res - sz); i <= res; ++i) {
			if (f(i) != -1) { res = i; break; }
		}
		cout << "Case #" << testId << ": " << res << ' ' << f(res) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}