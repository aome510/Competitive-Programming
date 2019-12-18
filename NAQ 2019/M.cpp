#include <bits/stdc++.h>

using namespace std;

long long w, g, h, r;


double f(double x) {
	return sqrt(x * x + (r - g) * (r - g)) + sqrt((w - x) * (w - x) + (h - r) * (h - r));
}

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	cout << fixed << setprecision(6);
	while (n--) {
		cin >> w >> g >> h >> r;
		if (g < h) swap(g, h);
		cout << sqrt(w * w + (g - h) * (g - h)) << ' ';
		double x = 1.0 * ((h - r) * (h - r) - (r - g) * (r - g) + w * w) / (2 * w);
		double y = 1.0 * ((g - r) * (g - r) - (h - r) * (h - r) + w * w) / (2 * w);
		// cout << min(f(x), f(y)) << '\n';
		cout << f(w / 2) << '\n';
		// cout << sqrt(w * w + (g - r) * (g - r)) + (h - r) << '\n';
	}
}