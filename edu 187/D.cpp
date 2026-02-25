#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (!(cin >> t))
    return 0;
  while (t--) {
    int n, m;
    cin >> n >> m;

    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int b[m];
    int max_b = 0;
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      if (b[i] > max_b) {
        max_b = b[i];
      }
    }

    sort(a, a + n);
    int total_unique = unique(a, a + n) - a;

    int P[max_b + 1];
    for (int i = 0; i <= max_b; i++) {
      P[i] = 0;
    }

    for (int i = 0; i < total_unique; i++) {
      int x = a[i];
      if (x > max_b)
        break;
      for (int k = x; k <= max_b; k += x) {
        P[k]++;
      }
    }

    int cA = 0, cB = 0, cAB = 0;
    for (int i = 0; i < m; i++) {
      int y = b[i];
      if (P[y] == 0) {
        cB++;
      } else if (P[y] == total_unique) {
        cA++;
      } else {
        cAB++;
      }
    }

    if (cA + (cAB % 2) > cB) {
      cout << "Alice\n";
    } else {
      cout << "Bob\n";
    }
  }
  return 0;
}
