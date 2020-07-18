#include <bits/stdc++.h>

using namespace std;

class AveragePrice {
public:
  double nonDuplicatedAverage(vector<int> prices) {
    sort(prices.begin(), prices.end());
    prices.erase(unique(prices.begin(), prices.end()), prices.end());
    int sum = 0;
    int n = prices.size();
    for (int i = 0; i < n; ++i)
      sum += prices[i];
    return 1.0 * sum / n;
  }
};
