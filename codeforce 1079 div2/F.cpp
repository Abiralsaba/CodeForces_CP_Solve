#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<pair<int, int>, int> dp;
    dp[{0, 0}] = 0;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char ops[] = {'(', ')', '[', ']'};

    for (int i = 0; i < n; i++) {
      map<pair<int, int>, int> ndp;
      int mn = 1e9;

      for (auto it : dp) {
        int x = it.first.first;
        int y = it.first.second;
        int c = it.second;

        if (x + y > n - i)
          continue;

        for (int j = 0; j < 4; j++) {
          int nx = x + dx[j];
          int ny = y + dy[j];

          if (nx < 0 || ny < 0)
            continue;

          int nc = c + (s[i] != ops[j]);

          if (ndp.find({nx, ny}) == ndp.end() || nc < ndp[{nx, ny}]) {
            ndp[{nx, ny}] = nc;
          }
        }
      }

      if (ndp.empty()) {
        dp = ndp;
        break;
      }

      int global_min = 1e9;
      for (auto it : ndp) {
        int val = it.second + it.first.first + it.first.second;
        if (val < global_min)
          global_min = val;
      }

      dp.clear();
      for (auto it : ndp) {
        if (it.second + it.first.first + it.first.second <= global_min + 6) {
          dp[it.first] = it.second;
        }
      }
    }

    if (dp.count({0, 0})) {
      cout << dp[{0, 0}] << endl;
    } else {
      cout << n << endl;
    }
  }
  return 0;
}
