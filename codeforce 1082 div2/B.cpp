#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string x;
    cin >> x;

    bool ok = true;
    if (n % 2 != 0) {
      if (x[0] == 'b') {
        ok = false;
      }
      for (int i = 1; i < n; i += 2) {
        if (x[i] != '?' && x[i + 1] != '?' && x[i] == x[i + 1]) {
          ok = false;
          break;
        }
      }
    } else {
      for (int i = 0; i < n; i += 2) {
        if (x[i] != '?' && x[i + 1] != '?' && x[i] == x[i + 1]) {
          ok = false;
          break;
        }
      }
    }

    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
