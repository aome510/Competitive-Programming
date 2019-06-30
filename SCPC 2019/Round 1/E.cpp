#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
long long L, R;
pair<long long, long long> a[N];

bool check(long long len) {
	long long cur = L;
	for (int i = 0; i < n; ++i) {
		if (a[i].second > len) continue;
		long long l = a[i].first - len, r = a[i].first + len;
		if (cur >= l) cur = max(cur, r);
	}
	return cur < R;
}

void solve(int idTest) {
	cin >> L >> R >> n;
	L *= 2, R *= 2;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		a[i].first *= 2, a[i].second *= 2;
		a[i].second = abs(a[i].second);
	}
	sort(a, a + n);
	long long l = 0, r = 2e12;
	while (l < r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid;
	}
	cout << "Case #" << idTest << '\n';
	cout << l << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}