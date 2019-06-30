#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int INF = 0x3f3f3f3f;

struct Lad {
	int x, a, b;

	bool operator < (const Lad& rhs) const {
		return x < rhs.x;
	}
};

int n, H;
int f[N][N * 2][N * 2][N * 2];
Lad lad[N];

void Unique(vector<int> &vec) {
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());	
}

int Find(vector<int> &vec, int val) {
	return lower_bound(vec.begin(), vec.end(), val) - vec.begin();
}

void upd(int &x, int y) { x = min(x, y); }

void solve(int testId) {
	cin >> n >> H;
	for (int i = 1; i <= n; ++i) {
		cin >> lad[i].x >> lad[i].a >> lad[i].b;
	}
	sort(lad + 1, lad + 1 + n);

	vector<int> vec;
	vec.push_back(0), vec.push_back(H);
	for (int i = 1; i <= n; ++i) {
		vec.push_back(lad[i].a);
		vec.push_back(lad[i].b);
	}
	Unique(vec);
	int sz = vec.size();
	int res = INF;

	f[0][0][0][0] = 0;
	for (int i = 1; i <= n + 1; ++i) {
		int a, b;
		if (i <= n) {
			a = Find(vec, lad[i].a);
			b = Find(vec, lad[i].b);
		}

		for (int j = 0; j < sz; ++j) {
			for (int k = 0; k < sz; ++k) for (int l = 0; l < sz; ++l) {
				int &tmp = f[i - 1][j][k][l];
				if (tmp == INF) continue;

				// cout << tmp << ' ' << i - 1 << ' ' << j << ' ' << k << ' ' << l << '\n';


				if (j < sz - 1) {
					if (i <= n) {
						// choose i
						if (k <= b && b <= l)
							upd(f[i][max(b, j)][b][l], tmp + vec[b] - vec[k]);
						else
							upd(f[i][max(b, j)][k][l], tmp);

						// block i
						if (a != 0 && b > j) {
							int _k, _l;
							if (l < a) {
								_k = max(k, a), _l = max(l, b);
							}
							else _k = min(k, a), _l = max(l, b);
							
							if (a <= j && j <= b)
								upd(f[i][a][_k][_l], tmp + vec[j] - vec[a]);
							else
								upd(f[i][j][_k][_l], tmp);
						}
					}
					else res = min(res, tmp);
				}

				tmp = INF;
			}
		}
	}

	cout << "Case #" << testId << ": " << (res == INF ? -1 : res) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	memset(f, INF, sizeof f);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}