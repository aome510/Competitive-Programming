#include <bits/stdc++.h>

using namespace std;

int D, P;
int sum[2][1005]; 

int main() {
	ios::sync_with_stdio(false);
	cin >> P >> D;
	while (P--) {
		int x, a[2];
		cin >> x >> a[0] >> a[1];
		sum[0][x] += a[0], sum[1][x] += a[1]; 
	}
	int sumAll[2];
	int V = 0;
	sumAll[0] = sumAll[1] = 0;
	for (int i = 1; i <= D; ++i) {
		int tmp = (sum[0][i] + sum[1][i]) / 2 + 1;
		if (sum[0][i] > sum[1][i]) {
			cout << "A " << (sum[0][i] - tmp) << ' ' << sum[1][i] << '\n';
			sumAll[0] += (sum[0][i] - tmp), sumAll[1] += sum[1][i];  
		} else {
			cout << "B " << sum[0][i] << ' ' << (sum[1][i] - tmp) << '\n';
			sumAll[0] += sum[0][i], sumAll[1] += (sum[1][i] - tmp);
		}
		V += sum[0][i] + sum[1][i];
	}
	cout << fixed << setprecision(6) << 1.0 * abs(sumAll[0] - sumAll[1]) / V;
}