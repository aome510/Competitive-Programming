#include <bits/stdc++.h>

using namespace std;

int n;
bool a[26];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char ch; cin >> ch; a[i] = ch == 'T';
	}
	string s;
	getline(cin, s);
	getline(cin, s);

	stack<bool> st;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') continue;
		if (s[i] >= 'A' && s[i] <= 'Z') {
			int id = s[i] - 'A';
			st.push(a[id]);
		}
		else {
			if (s[i] == '-') {
				bool t = (st.top()) ^ 1;
				st.pop();
				st.push(t);
			}
			else {
				bool x = st.top(); st.pop();
				bool y = st.top(); st.pop();
				if (s[i] == '*') {
					st.push(x & y);
				}
				else {
					st.push(x | y);
				}
			}
		}
	}
	cout << (st.top() ? 'T' : 'F');
}