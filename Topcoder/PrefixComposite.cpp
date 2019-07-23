#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const long long MAX = 1e11;

bool notprime[N];
vector<int> vec_prime;

void prep() {
	for (int i = 2; i < N; ++i) {
		if (notprime[i]) continue;
		if (1LL * i * i <= MAX) vec_prime.push_back(i);
		for (int j = i + i; j < N; j += i) notprime[j] = 1;
	}
}

bool checkComp(long long x) {
	for (auto i : vec_prime) {
		if (1LL * i * i > x) break;
		if (x % i == 0) return 1;
	}
	return 0;
}

class PrefixComposite {
public:
	int a[12], b[12];
	long long res[2];
	bool found;

	void backtrack(int pos, bool sm, bool gr, long long cur, bool type) {
		if (pos == 12) {
			found = 1, res[type] = cur;
			return;
		}
		int l = 0, r = 9;
		if (!sm) r = b[pos];
		if (!gr) l = a[pos];
		vector<int> vec;
		for (int i = l; i <= r; ++i) vec.push_back(i);
		if (type) reverse(vec.begin(), vec.end());
		for (auto i : vec) {
			if (found) break;
			long long tmp = cur * 10 + i;
			if (tmp) {
				if (pos < 7) {
					if (!notprime[tmp]) continue;
				}
				else {
					if (!checkComp(tmp)) continue;
				}
			}
			backtrack(pos + 1, sm | (i < r), gr | (i > l), tmp, type);
		}
	}

	vector<long long> minMax(long long A, long long B) {
		prep();
		for (int i = 0; i < 12; ++i) a[11 - i] = A % 10, A /= 10;
		for (int i = 0; i < 12; ++i) b[11 - i] = B % 10, B /= 10;
		found = 0;
		backtrack(0, 0, 0, 0, 0);
		found = 0;
		backtrack(0, 0, 0, 0, 1);
		vector<long long> vec;
		if (!found) return vec;
		vec.push_back(res[0]), vec.push_back(res[1]);
		return vec;
	}
} test;

// long long Rand() {
// 	return 1LL * (rand() % 10000) * (rand() % 10000) * (rand() % 1000) - (rand() % 10000) * (rand() % 1000) - rand() % 10000; 
// }

// int main() {
// 	prep();
// 	srand(time(0));
// 	while (1) {
// 		long long A, B; 
// 		// cin >> A >> B;
// 		A = Rand();
// 		B = Rand();
// 		if (A > B) swap(A, B);
// 		cout << A << ' ' << B << '\n'; 
// 		vector<long long> vec = test.minMax(A, B);
// 		for (auto i : vec) cout << i << ' ';
// 	}
// }