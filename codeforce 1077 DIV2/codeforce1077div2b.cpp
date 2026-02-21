#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        ans++;
    }

    int i = 0;
    while (i < n) {
      if (s[i] == '0') {
        int cnt = 0;
        while (i < n && s[i] == '0') {
          cnt++;
          i++;
        }
        int l = (i - cnt > 0) ? 1 : 0;
        int r = (i < n) ? 1 : 0;
        int x = cnt - l - r;
        if (x > 0)
          ans += (x + 2) / 3;
      } else
        i++;
    }
    cout << ans << "\n";
  }
  return 0;
}
