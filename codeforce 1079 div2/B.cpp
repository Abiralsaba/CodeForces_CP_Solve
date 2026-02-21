#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p[n], a[n];
    int pos[n + 1];
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      pos[p[i]] = i;
    }
    for (int i = 0; i < n; i++)
      cin >> a[i];

    bool ok = true;
    for (int i = 1; i < n; i++) {
      if (pos[a[i]] < pos[a[i - 1]]) {
        ok = false;
        break;
      }
    }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
