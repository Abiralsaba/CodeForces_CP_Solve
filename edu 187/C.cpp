#include <bits/stdc++.h>
using namespace std;

bool check(long long n, long long s, long long m) {
  long long V = s;
  for (int i = 60; i >= 0; i--) {
    if ((m >> i) & 1) {
      long long k = min(n, V / (1LL << i));
      V -= k * (1LL << i);
    }
  }
  return V == 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long s, m;
    cin >> s >> m;

    if (!check(s, s, m)) {
      cout << -1 << endl;
      continue;
    }

    long long l = 1, r = s, ans = -1;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      if (check(mid, s, m)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
