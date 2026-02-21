#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int mn = 1e9, mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < mn)
        mn = a[i];
      if (a[i] > mx)
        mx = a[i];
    }

    int b[n];
    for (int i = 0; i < n; i++)
      b[i] = a[i];
    sort(b, b + n);

    vector<int> bad;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i])
        bad.push_back(a[i]);
    }

    if (bad.size() == 0) {
      cout << -1 << endl;
      continue;
    }

    int ans = 1e9;
    for (int i = 0; i < bad.size(); i++) {
      int x = bad[i];
      int d1 = x - mn;
      int d2 = mx - x;
      int best;
      if (d1 > d2)
        best = d1;
      else
        best = d2;
      if (best < ans)
        ans = best;
    }
    cout << ans << endl;
  }
  return 0;
}
