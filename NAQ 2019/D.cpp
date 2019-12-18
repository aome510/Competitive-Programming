#include <bits/stdc++.h>

using namespace std;

int n, cnt = 1;
bool flag = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		int x; cin >> x;
		while (x > cnt) {
			flag = 1;
			cout << cnt++ << '\n';
		}
		cnt++;
	}
	if (!flag) cout << "good job\n";
}