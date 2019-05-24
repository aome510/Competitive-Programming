#include <bits/stdc++.h>

using namespace std;

class RulerMaker {
public:
	bool vis[1000005];

	bool check(int n, vector<int> &vec) {
		// cout << "#vec\n";
		// for (auto i : vec) cout << i << ' '; cout << '\n';

		for (int i = 1; i <= n * n / 4; ++i) vis[i] = 0;
		for (int i = 0; i < vec.size(); ++i) for (int j = 0; j < i; ++j) {
			vis[vec[i] - vec[j]] = 1;
		}
		for (int i = 1; i <= (n * n + 3) / 4; ++i) if (!vis[i]) return 0;
		return 1;
	}

	vector <int> placeStickers(int n) {
		vector<int> vec;
		int sum = 0;
		vec.push_back(0);
		for (int i = 1; i <= n / 2; ++i) vec.push_back(++sum);
		for (int i = n / 2 + 1; i < n; ++i) vec.push_back(sum += (n / 2 + 1));
		// cout << n << ' ' << vec.size() << '\n';
		// if (!check(n, vec)) {
		// 	cout << n << '\n';
		// }
		return vec;
	}
} test;

// int main() {
// 	for (int i = 2; i <= 1000; ++i) test.placeStickers(i);
// }