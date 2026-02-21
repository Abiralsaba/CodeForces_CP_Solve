#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    long long ans = 0;
    int K = 450;

    for (int i = 0; i < n; i++) {
      for (int v = 1; v <= K; v++) {
        long long dist = (long long)v * a[i];
        if (i - dist < 0)
          break;
        if (a[i - dist] == v)
          ans++;
      }
    }

    for (int i = 0; i < n; i++) {
      if (a[i] > K) {
        for (int v = 1;; v++) {
          long long j = i + (long long)a[i] * v;
          if (j >= n)
            break;
          if (a[j] == v)
            ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
