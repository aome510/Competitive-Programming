#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	sort(vec.begin(), vec.end(), [&] (int x, int y) {
		return x > y;
	});
	for (auto i : vec) cout << i << ' '; cout << '\n';
}