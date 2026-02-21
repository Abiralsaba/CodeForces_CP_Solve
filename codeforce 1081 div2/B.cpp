#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int c1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        c1++;
    }

    vector<int> ops;
    if (c1 % 2 == 0) {
      for (int i = 0; i < n; i++) {
        if (s[i] == '1')
          ops.push_back(i + 1);
      }
    } else if ((n - c1) % 2 == 1) {
      for (int i = 0; i < n; i++) {
        if (s[i] == '0')
          ops.push_back(i + 1);
      }
    } else {
      cout << -1 << endl;
      continue;
    }

    cout << ops.size() << endl;
    for (int i = 0; i < ops.size(); i++) {
      if (i > 0)
        cout << " ";
      cout << ops[i];
    }
    if (ops.size() > 0)
      cout << endl;
  }
  return 0;
}
