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

    int h[n];
    int last_hard = n;
    for (int i = n - 1; i >= 0; i--) {
      if (i + 1 < n && a[i + 1] > a[i] + 1) {
        last_hard = i + 1;
      }
      h[i] = last_hard;
    }

    int S[n];
    for (int i = 0; i < n; i++) {
      S[i] = n;
    }

    int st[n];
    int top = 0;
    for (int i = 0; i < n; i++) {
      while (top > 0 && a[st[top - 1]] >= a[i]) {
        S[st[top - 1]] = i;
        top--;
      }
      st[top++] = i;
    }

    long long c[n];
    for (int i = 0; i < n; i++) {
      c[i] = 1;
    }

    for (int i = 0; i < n; i++) {
      int nxt = min(h[i], S[i]);
      if (nxt < n) {
        c[nxt] += c[i];
      }
    }

    long long total = 1LL * n * (n + 1) / 2;
    for (int i = 1; i < n; i++) {
      total += 1LL * (n - i) * (c[i] - 1);
    }

    cout << total << endl;
  }
  return 0;
}
