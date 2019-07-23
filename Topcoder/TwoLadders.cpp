#include <bits/stdc++.h>

using namespace std;

class TwoLadders {
public:
	long long f[105][2];

	void upd(long long &x, long long y) { x = min(x, y); }

	long long minSteps(int sx, int lx1, int lx2, vector <int> X, vector <int> Y) {
		vector<int> vec;
		vec.push_back(0);
		for (auto i : Y) vec.push_back(i);
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		int n = X.size(), sz = vec.size();
		for (int i = 0; i < sz; ++i) {
			int l = 1e9, r = 0;
			for (int j = 0; j < n; ++j) {
				if (Y[j] == vec[i]) l = min(l, X[j]), r = max(r, X[j]);
			}
			if (i == 0) {
				if (l > r) l = r = sx;
				long long fl = abs(sx - r) + (r - l);
				long long fr = abs(sx - l) + (r - l);
				if (sz == 1) {
					return min(fl, fr);
				}
				f[1][0] = min(fl + abs(l - lx1), fr + abs(r - lx1)) + (vec[1] - vec[0]);
				f[1][1] = min(fl + abs(l - lx2), fr + abs(r - lx2)) + (vec[1] - vec[0]);
			}
			else {
				long long fl = min(f[i][0] + abs(lx1 - r) + (r - l), f[i][1] + abs(lx2 - r) + (r - l));
				long long fr = min(f[i][0] + abs(lx1 - l) + (r - l), f[i][1] + abs(lx2 - l) + (r - l));
				if (sz - 1 == i) {
					return min(fl, fr);
				}
				f[i + 1][0] = min(fl + abs(l - lx1), fr + abs(r - lx1)) + (vec[i + 1] - vec[i]);
				f[i + 1][1] = min(fl + abs(l - lx2), fr + abs(r - lx2)) + (vec[i + 1] - vec[i]);
			}
		}
		assert(0);
	}
} test;
	
// int sx = 10, lx1 = 8, lx2 = 11;
// vector<int> X = {10, 12}, Y = {1, 1};

// int main() {
// 	cout << test.minSteps(sx, lx1, lx2, X, Y) << '\n';
// }