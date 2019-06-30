#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

void solve(int idTest) {
	int R, e, n;
	double s;
	double dis = 0.0;
	cin >> R >> s >> e >> n;
	while (n--) {
		int l, r, h; cin >> l >> r >> h;
		if (h >= R) {
			dis += 0.0 + (l - R) - s;
			dis += 2.0 * (h - R);
			dis += PI * R;
			dis += 0.0 + r - l;
			s = r + R;
		}
		else {
			double gap = sqrt(1.0 * R * R - 1.0 * (R - h) * (R - h));
			dis += (l - gap) - s;
			dis += 0.0 + r - l;
			dis += 2.0 * R * acos(1.0 * (R - h) / R);
			s = r + gap;
		}
	}
	dis += e - s;

	cout << "Case #" << idTest << '\n';
	cout << fixed << setprecision(9) << dis << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}