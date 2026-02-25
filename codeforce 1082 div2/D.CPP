#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    if (k < n || k > 2 * n - 1) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;

    int c = (2 * n - 1) - k;

    int val = 1;
    for (int i = 0; i < c; i++) {
      cout << val << " " << val << " ";
      val++;
    }

    int m = n - val + 1;
    if (m > 0) {
      int v[m];
      for (int i = 0; i < m; i++) {
        v[i] = val + i;
      }

      for (int i = 0; i < m; i++) {
        if (i == 0) {
          cout << v[0] << " ";
        } else {
          cout << v[i] << " " << v[i - 1] << " ";
        }
      }
      cout << v[m - 1] << " ";
    }
    cout << endl;
  }
  return 0;
}
