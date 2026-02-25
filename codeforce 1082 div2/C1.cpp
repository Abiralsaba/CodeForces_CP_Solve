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

    int ans = 0;
    int R = -1, x = -1;

    for (int i = 0; i < n; i++) {
      if (i == 0) {
        ans++;
        R = a[i];
        x = a[i];
      } else {
        if (a[i] >= R + 1 && a[i] <= x + 1) {
          x = a[i];
        } else {
          ans++;
          R = a[i];
          x = a[i];
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}
