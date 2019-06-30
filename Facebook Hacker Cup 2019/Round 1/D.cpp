#include <bits/stdc++.h>

using namespace std;

const int N = 800005;
const int INF = 2e9 + 7;

int n, H, V;
int p[N];
int a[2][N];
int bit[N];
int fMax[N], fCnt[N];
int fX[N], fY[N];
int res;

void init() {
	for (int i = 1; i <= n; ++i) bit[i] = 0;
}

void upd(int x) {
	for (x; x > 0; x -= x & -x) bit[x]++;
}

int get(int x) {
	int ans = 0;
	for (x; x <= n; x += x & -x) ans += bit[x];
	return ans;
}

void calc() {
	// for each i calculate number of j(s) 
	// such that (a[1][j], j) > (a[1][i], i) 
	// and max a[0][j] 

	for (int i = 1; i <= n; ++i) p[i] = i;
	sort(p + 1, p + 1 + n, [&] (int x, int y) {
		return make_pair(a[1][x], a[0][x]) > make_pair(a[1][y], a[0][y]);
	});
	int cur_max = 0;
	for (int i = 1; i <= n; ++i) {
		fMax[p[i]] = cur_max, fCnt[p[i]] = i - 1;
		cur_max = max(cur_max, a[0][p[i]]);
	}

	// sort p based on a[0]
	sort(p + 1, p + 1 + n, [&] (int x, int y) {
		return make_pair(a[0][x], a[1][x]) < make_pair(a[0][y], a[1][y]);
	});

	// compress a[0]
	vector<int> vec;
	for (int i = 1; i <= n; ++i) vec.push_back(a[0][i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	// for each i calculate number of j such that
	// pos(j) in p < pos(i) in p and a[0][j] > fMax[i]
	init();
	for (int i = 1; i <= n; ++i) {
		int tmp;
		if (fMax[p[i]]) {
			tmp = lower_bound(vec.begin(), vec.end(), fMax[p[i]]) - vec.begin() + 1;
			fX[p[i]] = get(tmp);
		}

		tmp = lower_bound(vec.begin(), vec.end(), a[0][p[i]]) - vec.begin() + 1;
		upd(tmp);
	}

	// compress a[1]
	vec.clear();
	for (int i = 1; i <= n; ++i) vec.push_back(a[1][i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	init();
	for (int i = n; i >= 1; --i) {
		int tmp;
		// get reverse position in vec to use the same BIT structure 
		tmp = n - (lower_bound(vec.begin(), vec.end(), a[1][p[i]]) - vec.begin());

		fY[p[i]] = get(tmp + 1);
		upd(tmp);
	}

	for (int i = 1; i <= n; ++i) {
		if (fMax[i] == 0) continue;

		if (V - 1 - fY[i] - fX[i] < 0 || H - fCnt[i] < 0) continue;
		res = min(res, a[1][i] + fMax[i]);
	}
	if (H >= n) res = min(res, *max_element(a[0] + 1, a[0] + 1 + n));
}

void solve(int testId) {
	cin >> n >> H >> V;
	for (int i = 0; i < 2; ++i) {
		int A, B, C, D;
		cin >> a[i][1] >> a[i][2] >> A >> B >> C >> D;
	
		for (int j = 3; j <= n; ++j) {
			a[i][j] = (1LL * A * a[i][j - 2] + 1LL * B * a[i][j - 1] + C) % D + 1;
		}
	}
	if (H + V < n) {
		cout << "Case #" << testId << ": -1\n"; return;
	}

	// for (int i = 1; i <= n; ++i) cout << a[0][i] << ' ' << a[1][i] << '\n';
	res = INF;
	calc();
	for (int i = 1; i <= n; ++i) swap(a[0][i], a[1][i]);
	swap(H, V);
	calc();

	cout << "Case #" << testId << ": " << (res == INF ? -1 : res) << '\n'; 
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}