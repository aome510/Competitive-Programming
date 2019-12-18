#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	long long x, y; cin >> x >> y;
	long long z = __gcd(x, y);
	if (((x / z) & 1) && ((y / z) & 1)) cout << z;
	else cout << 0;
}