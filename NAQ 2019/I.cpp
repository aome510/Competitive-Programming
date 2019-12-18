#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const long long INF = 1e18;

int n, m, t, D;
int a[N];
long long d[N][N];
long long f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> t >> D;
	t += 2;
	a[1] = 1;
	for (int i = 2; i <= t - 1; ++i) cin >> a[i];
	a[t] = n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			f[i][j] = d[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; ++i) d[i][i] = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		d[u][v] = d[v][u] = min(d[u][v], 0LL + w);
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 1; i <= t; ++i) f[i][i] = 0;
	for (int i = 1; i <= t; ++i) {
		for (int j = 1; j <= t; ++j) {
			if (d[a[i]][a[j]] <= D) f[i][j] = d[a[i]][a[j]];
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	if (f[1][t] == INF) cout << "stuck"; else cout << f[1][t];
}