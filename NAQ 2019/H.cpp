#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n;
int f[N][N];
bool a[N][N];

int cal(int l, int r) {
	int &F = f[l][r];
	if (F != -1) return F;
	if (l == r) return F = 0;
	F = 0;
	F = max(F, cal((l + 1) % n, r));
	int t = l;
	while (t != r) {
		t = (t + 1) % n;
		if (a[l][t]) {
			int tmp = 1;
			if ((l + 1) % n != t) tmp += cal((l + 1) % n, (t - 1 + n) % n);
			if (t != r) tmp += cal((t + 1) % n, r);
			F = max(F, tmp);
		}
	}
	return F;
}

int main() {
	ios::sync_with_stdio(false);
	memset(f, -1, sizeof f);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	cout << cal(0, n - 1);
}