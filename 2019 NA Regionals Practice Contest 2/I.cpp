#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n;
int in[N], out[N];
bool a[N][N];
bool del[N];

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < n; ++i) in[i] = out[i] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                char ch; cin >> ch;
                a[i][j] = ch - '0';
                a[j][i] = 1 - a[i][j];
                if (a[i][j]) in[i]++, out[j]++;
                else in[j]++, out[i]++;
            }
        }
        for (int i = 0; i < n; ++i) cout << in[i] << '\n';
        int mx = 0;
        for (int i = 0; i < n; ++i) {
        	mx = max(mx, out[i]);
        }
        cout << mx << '\n';
    }
}
