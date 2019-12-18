#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

long long cnt;
int bit[N];
int nxt[N];
vector<int> vec[26];

void upd(int x) {
	for (x; x < N; x += x & -x) bit[x]++;
}

int get(int x) {
	int res = 0;
	for (; x > 0; x -= x & -x) res += bit[x];
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	string s; cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		vec[s[i] - 'a'].push_back(i + 1);
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j + 1 < vec[i].size(); ++j) {
			nxt[vec[i][j]] = vec[i][j + 1];
		}
		if (vec[i].size()) {
			upd(vec[i][0]);
			nxt[vec[i].back()] = s.size() + 1;
		}
	}
	for (int i = 1; i <= s.size(); ++i) {
		cnt += get(nxt[i] - 1) - get(i);
		if (nxt[i]) upd(nxt[i]);
	}
	cout << cnt << '\n';
}