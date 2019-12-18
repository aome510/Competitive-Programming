#include <bits/stdc++.h>

using namespace std;

string s;
int n;
string t[100005];
int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin >> s >> n;
    for (int i = 0; i < n; ++i) cin >> t[i];
    bool found = 0;
    for (int i = 0; i < n; ++i) {
        cnt[t[i][0] - 'a']++;
        if (t[i][0] == s[s.size() - 1]) found = 1;
    }
    if (!found) {
        cout << "?"; return 0;
    }
    string res;
    for (int i = 0; i < n; ++i) {
        if (t[i][0] == s[s.size() - 1]) {
            cnt[t[i][0] - 'a']--;
            if (!cnt[t[i][t[i].size() - 1] - 'a']) {
                res = t[i] + '!'; 
                break;
            }
            else if (res == "") res = t[i];
            cnt[t[i][0] - 'a']++;
        } 
    }
    cout << res;
}
