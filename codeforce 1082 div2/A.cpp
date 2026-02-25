#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;

    long long val = x + 4 * y;
    bool ok = false;

    if (val >= 0 && val % 3 == 0) {
      long long s = val / 3;
      long long mx = max(0LL, y);
      if (2 * mx <= s) {
        ok = true;
      }
    }

    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
