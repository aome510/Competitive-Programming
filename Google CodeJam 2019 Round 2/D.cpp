#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int mod = 1e9 + 7;
const int INF = 1e9;

int n, cnt;
int cntComp;
int a[N];
int low[N], num[N];
int label[N];
int deg[N];
int sum[N];
int edge[N];
bool unbounded[N];
bool notzero[N];
vector<int> G[N], G2[N];
vector<int> vec[N];
stack<int> st;

void dfs(int u) {
	low[u] = num[u] = ++cnt;
	st.push(u);
	for (auto v : G[u]) {
		if (num[v]) low[u] = min(low[u], num[v]);
		else dfs(v), low[u] = min(low[u], low[v]);
	}

	if (num[u] == low[u]) {
		++cntComp;
		int v = -1;
		while (v != u) {
			v = st.top(), st.pop();
			low[v] = num[v] = INF;
			label[v] = cntComp, vec[cntComp].push_back(v);
			sum[cntComp] = (sum[cntComp] + a[v]) % mod;
			notzero[cntComp] |= (a[v] != 0);
		}
	}
}

void solve(int testId) {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		sum[i] = unbounded[i] = deg[i] = notzero[i] = edge[i] = 0;
		G2[i].clear(), G[i].clear(), vec[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		int u, v; cin >> u >> v;
		G[i].push_back(u), G[i].push_back(v);
	}
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cnt = cntComp = 0;
	for (int i = 1; i <= n; ++i) {
		low[i] = num[i] = 0;
	}
	while (st.size()) st.pop();
	for (int i = 1; i <= n; ++i) if (!num[i]) dfs(i);
	for (int i = 1; i <= n; ++i) {
		for (auto j : G[i]) {
			if (label[i] != label[j]) {
				G2[label[i]].push_back(label[j]);
				deg[label[j]]++;
				// cout << label[i] << ' ' << label[j] << '\n';
			}
			else edge[label[i]]++;
		}
	}
	queue<int> qu;
	for (int i = 1; i <= cntComp; ++i) {
		// cout << "#at " << i << '\n';
		// for (auto j : vec[i]) cout << j << ' '; cout << '\n';
		if (deg[i] == 0) qu.push(i);
	}
	while (qu.size()) {
		int u = qu.front(); qu.pop();
		if (vec[u].size() > 1 && notzero[u]) {
			if (u != label[1] || edge[u] != vec[u].size()) unbounded[u] = 1;
		}
		else if (vec[u].size() == 1 && notzero[u] && edge[u] && u != label[1]) unbounded[u] = 1;
		for (auto v : G2[u]) {
			notzero[v] |= notzero[u];
			unbounded[v] |= unbounded[u];
			sum[v] = (sum[v] + sum[u]) % mod;
			deg[v]--;
			if (deg[v] == 0) qu.push(v);
		}
	}
	if (unbounded[label[1]]) {
		cout << "Case #" << testId << ": " << "UNBOUNDED\n";
	}
	else {
		cout << "Case #" << testId << ": " << sum[label[1]] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}