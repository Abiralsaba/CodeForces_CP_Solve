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
      if (s[i] != s[(i + 1) % n])
        ans++;
    }

    cout << min(n, ans + 1) << endl;
  }
  return 0;
}
