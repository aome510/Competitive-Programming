#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n;
long long a[N];
vector<int> G[N];
bool fail = 0;

void go(int u, vector<int>&vec, int &sum) {
    for (auto v : G[u]) {
        if (a[v]) sum -= a[v];
        else go(v, vec, sum);
    }
    if (!G[u].size() && !a[u]) vec.push_back(u);
}

void dfs(int u) {
    for (auto v : G[u]) dfs(v);
    if (a[u] && G[u].size()) {
        vector<int> vec;
        int sum = a[u];
        go(u, vec, sum);
        /* cout << "DFS\n"; */
        /* cout << u << ' ' << sum << '\n'; */
        /* for (auto i : vec) cout << i << ' '; cout << '\n'; */
        if (sum < 0) {
            fail = 1; return;
        }
        if (vec.size() == 1) {
            if (sum == 0) {
                fail = 1; return;
            }
            a[vec[0]] = sum;
            return;
        }
        if (sum != vec.size()) {
            fail = 1; return;
        }
        for (auto i : vec) a[i] = 1;
    }
}

void check(int u) {
    long long sum = 0;
    for (auto v : G[u]) {
        check(v);
        sum += a[v];
    }
    if (G[u].size() && a[u] != 0 && a[u] != sum) {
        /* cout << "Check\n"; */
        /* cout << u << ' ' << a[u] << ' ' << sum << '\n'; */
        fail = 1; return;
    }
    if (G[u].size()) a[u] = sum;
}

void solve() {
    fail = 0;
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p, G[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1);
    if (fail) {
        cout << "impossible\n"; return;
    }
    check(1);
    assert(fail == 0);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            cout << "impossible\n"; return;
        }
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        solve();
    }
}
