#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int INF = 1e9;
const int mod = 1e9 + 7;

int n, m;
int pw[N];
int it[4 * N];
int lazy[4 * N];
string s;

#define mid ((l + r) >> 1)

void push(int i, int l, int r) {
	it[i] += lazy[i];
	if (l != r) {
		lazy[i << 1] += lazy[i], lazy[i << 1 | 1] += lazy[i];
	}
	lazy[i] = 0;
}

void upd(int i, int l, int r, int L, int R, int val) {
	push(i, l, r);
	if (l > R || L > r) return;
	if (L <= l && r <= R) {
		lazy[i] = val, push(i, l, r); return;
	}
	upd(i << 1, l, mid, L, R, val);
	upd(i << 1 | 1, mid + 1, r, L, R, val);
	it[i] = max(it[i << 1], it[i << 1 | 1]);
}

int get(int i, int l, int r, int L, int R) {
	push(i, l, r);
	if (l > R || L > r) return -INF;
	if (L <= l && r <= R) return it[i];
	return max(get(i << 1, l, mid, L, R), get(i << 1 | 1, mid + 1, r, L, R));
}

#undef mid

void solve(int testId) {
	cin >> n >> m >> s;
	
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) pw[i] = 2 * pw[i - 1] % mod;
	for (int i = 1; i <= 4 * n; ++i) it[i] = lazy[i] = 0;

	int cost = 0;
	for (int i = n; i >= 1; --i) {
		int tmp = (s[i - 1] == 'B' ? 1 : -1);
		if (get(1, 1, n, i, n) + tmp > m) {
			tmp = -1;
			cost = (cost + pw[i]) % mod;
		}
		upd(1, 1, n, i, n, tmp);
	}
	cout << "Case #" << testId << ": " << cost << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}