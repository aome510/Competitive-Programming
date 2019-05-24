#include <bits/stdc++.h>

using namespace std;

const int N = 65;

class Byes {
public:

	int need;
	long long curr;
	long long value;
	long long res = 2e18;
	bool vis[N][2][3][N][N];

	void backtrack(int pos, bool greater, int cnt, int cntZero, int cntByes) {
		if (pos == -1) {
			if (cntByes == need) res = min(res, curr); return;
		}
		if (vis[pos][greater][cnt][cntZero][cntByes]) return;
		vis[pos][greater][cnt][cntZero][cntByes] = 1;

		if (greater) {
			backtrack(pos - 1, 1, cnt, cntZero + 1, cntByes);
			curr += 1LL << pos; 
			backtrack(pos - 1, 1, min(2, cnt + 1), 0, cntByes + (cnt != 0) * cntZero + (cnt == 1));
			curr -= 1LL << pos;
		}
		else {
			bool t = value >> pos & 1;
			if (t == 1) {
				curr += 1LL << pos;
				backtrack(pos - 1, 0, min(2, cnt + 1), 0, cntByes + (cnt != 0) * cntZero + (cnt == 1));
				curr -= 1LL << pos;
			}
			else {
				backtrack(pos - 1, 0, cnt, cntZero + 1, cntByes);
				curr += 1LL << pos;
				backtrack(pos - 1, 1, min(2, cnt + 1), 0, cntByes + (cnt != 0) * cntZero + (cnt == 1));
				curr -= 1LL << pos;
			}
		}
	}

	long long getNumberOfPlayers(long long lowerBound, int numberOfByes) {
		value = lowerBound, need = numberOfByes;
		// for (int i = 60; i >= 0; --i) cout << (value >> i & 1); cout << '\n';
		backtrack(60, 0, 0, 0, 0);
		return res;
	}
} test;

// int main() {
// 	long long lowerBound;
// 	int numberOfByes;
// 	cin >> lowerBound >> numberOfByes;
// 	cout << test.getNumberOfPlayers(lowerBound, numberOfByes);
// }