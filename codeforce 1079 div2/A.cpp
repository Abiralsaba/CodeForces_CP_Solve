#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long x;
    cin >> x;

    int ans = 0;
    for (long long y = x + 1; y <= x + 200; y++) {
      long long tmp = y;
      int ds = 0;
      while (tmp > 0) {
        ds += tmp % 10;
        tmp /= 10;
      }
      if (y - ds == x)
        ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
