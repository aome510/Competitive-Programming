#include <bits/stdc++.h>

using namespace std;

struct Req {
	int x, y, w;
};

const int INF = 1e6;

int n, m;
int dis[55][55];
Req a[1005];

void init() {
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dis[i][j] = INF;
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
}

void floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

void solve(int testId) {
	cin >> n >> m;
	init();	
	for (int i = 1; i <= m; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].w;
		dis[a[i].x][a[i].y] = dis[a[i].y][a[i].x] = min(dis[a[i].x][a[i].y], a[i].w);
	}
	floyd();
	cout << "Case #" << testId << ": ";
	for (int i = 1; i <= m; ++i) {
		if (dis[a[i].x][a[i].y] != a[i].w) {
			cout << "Impossible\n"; return;
		}
	}
	cout << n * (n - 1) / 2 << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}