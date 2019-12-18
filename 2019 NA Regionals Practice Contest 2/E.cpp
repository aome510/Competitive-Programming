#include <bits/stdc++.h>

using namespace std;

int n;
bool vis[105];
string a[105];

int main() {
    string s;
    getline(cin, s);
        int cnt = 1;
        for (int i = 0; i < s.size(); ++i) cnt += s[i] == ' ';
        cin >> n;
        vector<string> vec[2];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < cnt; ++j) {
                if (j) {
                    ptr = (ptr + 1) % n;
                }
                while (vis[ptr]) {
                    ptr = (ptr + 1) % n;
                }
            }
            vec[i & 1].push_back(a[ptr]);
            vis[ptr] = 1;
            ptr = (ptr + 1) % n;
        }
        for (int i = 0; i < 2; ++i) {
            cout << vec[i].size() << '\n';
            for (auto j : vec[i]) cout << j << '\n';
        
        }
}
