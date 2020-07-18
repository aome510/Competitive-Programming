#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m;
int a[N];
int par[N];
int parEdge[N];
int costEdge[N];
int sum[N], h[N], f[N];
int nxt[N], nxtEdge[N];
vector<pair<int, int>> G[N];
vector<int> vec[N];
bool vis[N];

bool find(int u, int x, int mx) {
  if (u == x)
    return 1;
  vis[u] = 1;
  for (auto i : G[u]) {
    int v = i.first;
    int edgeID = i.second;
    if (par[u] == v)
      continue;
    if (a[v] > 0 && mx >= a[v])
      continue;
    if (a[v] < 0 && a[x] < 0 && v != x && a[v] <= a[x])
      continue;
    if (vis[v])
      continue;
    if (par[v] && par[v] != u)
      continue;
    if (find(v, x, max(mx, a[v]))) {
      if (f[u] > f[v] + 1) {
        f[u] = f[v] + 1, nxt[u] = v, nxtEdge[u] = edgeID;
      }
    }
  }
  return 0;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    sum[i] = par[i] = 0, G[i].clear(), vec[i].clear();
  for (int i = 2; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    costEdge[i] = 0;
    int u, v;
    cin >> u >> v;
    G[u].push_back({v, i}), G[v].push_back({u, i});
  }
  for (int i = 2; i <= n; ++i) {
    if (a[i] < 0) {
      vec[-a[i]].push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (auto j : vec[i]) {
      for (int k = 1; k <= n; ++k)
        vis[k] = 0, f[k] = 1e6;
      f[j] = 0;
      find(1, j, 0);
      int cur = 1;
      while (cur != j) {
        par[nxt[cur]] = cur, h[nxt[cur]] = h[cur] + 1,
        parEdge[nxt[cur]] = nxtEdge[cur];
        cur = nxt[cur];
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (!par[i]) {
      for (int k = 1; k <= n; ++k)
        vis[k] = 0, f[k] = 1e6;
      find(1, i, 0);
      f[i] = 0;
      int cur = i;
      while (cur != i) {
        par[nxt[cur]] = cur, h[nxt[cur]] = h[cur] + 1,
        parEdge[nxt[cur]] = nxtEdge[cur];
        cur = nxt[cur];
      }
    }
  }
  // for (int i = 1; i <= n; ++i)
  //   cout << par[i] << ' ';
  // cout << '\n';
  // return;
  for (int i = 1; i <= n; ++i)
    vis[i] = 0;
  vis[1] = 1;
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    vector<int> buf;
    for (auto j : vec[i]) {
      int cur = j;
      while (1) {
        if (vis[cur])
          break;
        buf.push_back(cur), vis[cur] = 1, cur = par[cur];
      }
    }
    sort(buf.begin(), buf.end(), [&](int u, int v) { return h[u] < h[v]; });
    for (auto j : buf) {
      if (a[j] > 0) {
        sum[j] = a[j];
        costEdge[parEdge[j]] = sum[j] - sum[par[j]];
        mx = max(mx, sum[j]);
      }
    }
    for (auto j : buf) {
      if (a[j] < 0) {
        sum[j] = mx + 1;
        costEdge[parEdge[j]] = sum[j] - sum[par[j]];
      }
    }
    for (auto j : buf)
      mx = max(mx, sum[j]);
  }
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) {
      int cur = i;
      vector<int> buf;
      while (1) {
        if (vis[cur])
          break;
        buf.push_back(cur), vis[cur] = 1, cur = par[cur];
      }
      reverse(buf.begin(), buf.end());
      for (auto j : buf) {
        if (a[j] > 0) {
          sum[j] = a[j];
          costEdge[parEdge[j]] = sum[j] - sum[par[j]];
        }
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (!costEdge[i])
      costEdge[i] = 1e6;
    cout << costEdge[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
