#include <bits/stdc++.h>

using namespace std;

void solve(int idTest) {
	string s;
	cin >> s;
	int sz = s.size();
	int low, high, cnt = 0;
	high = sz - 2, low = sz / 2;
	for (auto i : s) if (i == 'B') ++cnt;
	cout << "Case #" << idTest << ": " << ((low <= cnt && cnt <= high) ? 'Y' : 'N') << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}