#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += s[i] - '0';
    }

    if (sum <= 9) {
      cout << 0 << endl;
      continue;
    }

    int need = sum - 9;
    int ans = n + 5;

    for (int i = 0; i < n; i++) {
      int max_reduce = s[i] - '0';
      if (i == 0)
        max_reduce--;
      if (max_reduce >= need) {
        ans = min(ans, 1);
      }
    }

    if (ans == 1) {
      cout << 1 << endl;
      continue;
    }

    int reductions[n];
    for (int i = 0; i < n; i++) {
      int max_reduce = s[i] - '0';
      if (i == 0)
        max_reduce--;
      reductions[i] = max_reduce;
    }

    sort(reductions, reductions + n, greater<int>());

    int current_reduced = 0;
    int moves = 0;
    for (int i = 0; i < n; i++) {
      current_reduced += reductions[i];
      moves++;
      if (current_reduced >= need) {
        ans = min(ans, moves);
        break;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
