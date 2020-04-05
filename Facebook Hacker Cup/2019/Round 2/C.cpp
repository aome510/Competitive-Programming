#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const int INF = 1e9;

int H, S, K;
char P[N][N];
int res[N * N];
int f[N][N][N][3];
pair<int, int> a[N];

void upd(int &x, int y) { x = min(x, y); }

void solve(int testId) {
	cin >> H >> S >> K;
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= S; ++j) {
			char ch; cin >> ch;
			P[j][i] = ch - 'A';
		}
	}
	for (int i = 1; i <= S; ++i) {
		a[i] = {0, 2};
		reverse(P[i] + 1, P[i] + 1 + H);
		for (int j = 1; j <= H; ++j) {
			if (P[i][j] != a[i].second) a[i].first++, a[i].second = P[i][j];
		}
	}
	// init dp
	for (int i = 1; i <= S; ++i) {
		for (int j = 0; j <= H; ++j) {
			for (int k = 0; k <= j; ++k) {
				for (int l = 0; l < 3; ++l) {
					f[i][j][k][l] = INF;
				}
			}
		}
	}
	for (int i = 1; i <= S; ++i) {
		f[i][0][0][2] = 0;
		for (int j = 1; j <= H; ++j) {
			for (int k = 0; k < j; ++k) {
				for (int l = 0; l < 3; ++l) {
					int ret = f[i][j - 1][k][l];
					if (ret == INF) continue;
					
					// erase j
					upd(f[i][j][k][l], ret + 1);
					// not erase j
					upd(f[i][j][k + (l != P[i][j])][P[i][j]], ret); 
				}
			}
		}
		for (int j = 1; j <= H; ++j) {
			for (int l = 0; l < 2; ++l) {
				upd(f[i][H][j][l], f[i][H][j - 1][l]);
			}
		}
		f[i][H][0][0] = f[i][H][0][1] = f[i][H][0][2]; // = H
	}

	// for (int i = 1; i <= S; ++i) {
	// 	cout << f[i][H][1][0] << ' ' << f[i][H][1][1] << '\n';
	// }

	int cur = H + 1;
	for (int i = 0; i < S * H; ++i) {
		while (cur > 1) {
			int costA = 0, costB = 0;
			// A on top
			for (int j = 1; j <= S; ++j) {
				if (a[j].first < cur - 1) continue;
				int tmp = min(f[j][H][cur - 1][0], f[j][H][cur - 2][1]);
				costA += tmp;
			}
			// B on top
			for (int j = 1; j <= S; ++j) {
				if (a[j].first < cur - 1) continue;
				int tmp = min(f[j][H][cur - 1][1], f[j][H][cur - 2][0]);
				costB += tmp;
			}

			// cout << cur << ' ' << i << ' ' << costA << ' ' << costB << '\n';

			if (min(costA, costB) <= i) cur--;
			else break;
		}
		res[i] = cur;
	}

	cout << "Case #" << testId << ": ";
	for (int i = 1; i <= K; ++i) {
		int x; cin >> x; cout << res[x] << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
}