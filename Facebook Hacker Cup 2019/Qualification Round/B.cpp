#include <bits/stdc++.h>

using namespace std;

void solve(int idTest) {
	string s;
	cin >> s;
	int sz = s.size();
	int cnt = 0;
	for (auto i : s) cnt += (i == 'B');
	cout << "Case #" << idTest << ": ";
	if (sz - (cnt + 1) == 0) {
		cout << "N\n"; return;
	}
	if (sz - (cnt + 1) == 1) {
		cout << ((cnt == 0) ? "N" : "Y") << '\n';
		return;
	}
	cout << ((cnt < 2) ? "N" : "Y") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}