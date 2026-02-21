#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long h, k;
    cin >> n >> h >> k;

    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    long long p[n];
    p[0] = a[0];
    for (int i = 1; i < n; i++) {
      p[i] = p[i - 1] + a[i];
    }

    long long s = p[n - 1];
    long long c = (h - 1) / s;
    long long h_rem = h - c * s;

    long long mn[n];
    mn[0] = a[0];
    for (int i = 1; i < n; i++) {
      mn[i] = min(mn[i - 1], a[i]);
    }

    long long mx[n];
    mx[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      mx[i] = max(mx[i + 1], a[i]);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long gain = 0;
      if (i + 1 < n) {
        gain = max(0LL, mx[i + 1] - mn[i]);
      }
      if (p[i] + gain >= h_rem) {
        ans = c * (n + k) + i + 1;
        break;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
