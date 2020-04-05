#include <bits/stdc++.h>

using namespace std;

char Not(char x) {
	if (x == '0') return '1';
	if (x == '1') return '0';
	if (x == 'X') return 'x';
	if (x == 'x') return 'X';
}

char Xor(char x, char y) {
	if (y == '0') return x;
	if (y == '1') return Not(x);
	if (y == 'x' || y == 'X') return (x != y) + '0'; 
}

char And(char x, char y) {
	if (y == '0') return '0';
	if (y == '1') return x;
	if (y == 'x' || y == 'X') return (x == y) ? x : '0';
}

char Or(char x, char y) {
	if (y == '0') return x;
	if (y == '1') return '1';
	if (y == 'x' || y == 'X') return (x == y) ? x : '1';	
}

void solve(int idTest) {
	string s; cin >> s;

	stack<char> st;

	for (auto c : s) {
		if (c != ')') {
			st.push(c);
		} else {
			assert(st.size() >= 4);
			char x = st.top(); st.pop();

			while (st.top() != '(') {
				assert(st.size() >= 3);
				char op = st.top(); st.pop();
				char y = st.top(); st.pop();

				if (y == 'x' || y == 'X') swap(x, y);
				if (y == 'x' || y == 'X') swap(x, y);
				if (y == 'x' || y == 'X') swap(x, y);

				if (op == '^') x = Xor(x, y);
				else if (op == '&') x = And(x, y);
				else x = Or(x, y);
			}

			st.pop();
			st.push(x);
		}
	}

	cout << "Case #" << idTest << ": " << (st.top() == 'x' || st.top() == 'X') << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
}