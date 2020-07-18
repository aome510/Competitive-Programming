#include <bits/stdc++.h>

using namespace std;

class RoomPairs {
public:
  vector<string> handle(int cutPos, int R, int C, int left) {
    cout << "handle: " << cutPos << ' ' << R << ' ' << C << ' ' << left << '\n';
    vector<string> ret;
    // base building
    for (int i = 0; i < 2 * R + 1; ++i) {
      string s;
      for (int j = 0; j < 2 * C + 1; ++j) {
        if (i % 2 == 0 && j % 2 == 0)
          s += '+';
        else
          s += ' ';
      }
      ret.push_back(s);
    }

    // build border
    for (int j = 1; j < 2 * C + 1; j += 2)
      ret[0][j] = ret[2 * R][j] = '-';
    for (int i = 1; i < 2 * R + 1; i += 2)
      ret[i][0] = ret[i][2 * C] = '|';

    // build lower part
    for (int i = cutPos; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        ret[i * 2][j * 2 + 1] = '-';
        ret[i * 2 + 1][j * 2] = '|';
      }
    }

    if (left == 0)
      return ret;

    // build border for cut position
    if (cutPos > 0 && cutPos <= R) {
      for (int j = 0; j < C; ++j) {
        ret[cutPos * 2][j * 2 + 1] = '-';
      }
    }
    assert(left <= 2 * C - 1);

    if (left < C - 1) {
      for (int i = 0; i < cutPos; ++i) {
        for (int j = 0; j < left; ++j) {
          ret[i * 2 + 1][(j + 1) * 2] = '|';
        }
      }
    } else if (left % 2 == 1) {
      assert(R > 1);
      for (int j = 1; j <= left / 2; ++j) {
        ret[1][j * 2] = '|';
      }
      for (int j = 0; j < C; ++j)
        ret[2][j * 2 + 1] = '-';
    } else {
      // cout << "...";
      assert(R > 1);
      if (left == 2) {
        if (R == 2 && C == 2)
          return vector<string>();
        assert(cutPos > 0 && cutPos <= 2);
        ret[cutPos * 2 + 1][2] = ' ';
        left += 2;
      }
      left--;
      for (int j = 1; j <= left / 2; ++j) {
        ret[1][j * 2] = '|';
      }
      for (int j = 0; j < C; ++j)
        ret[2][j * 2 + 1] = '-';
      for (int i = 1; i < cutPos; ++i) {
        ret[i * 2 + 1][2] = '|';
      }
    }

    return ret;
  }

  vector<string> construct(int R, int C, int N) {
    int cur = (R - 1) * C + R * (C - 1);
    int cnt = 0;
    while (1) {
      // cout << N << ' ' << cur << '\n';
      if (N >= cur) {
        return handle(cnt, R, C, N - cur);
      }
      cur -= (C - 1);
      if (cnt > 0)
        cur -= C;
      cnt++;
    }
  }
} test;

int main() {
  int R, C, N;
  cin >> R >> C >> N;
  vector<string> ret = test.construct(R, C, N);
  for (int i = 0; i < ret.size(); ++i) {
    for (int j = 0; j < ret[0].size(); ++j) {
      cout << ret[i][j];
    }
    cout << '\n';
  }
}
