#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int par[n], dep[n];
    vector<int> ord;
    vector<vector<int>> ch(n);
    par[0] = -1;
    dep[0] = 0;
    ord.push_back(0);
    for (int i = 0; i < (int)ord.size(); i++) {
      int u = ord[i];
      for (int j = 0; j < (int)adj[u].size(); j++) {
        int w = adj[u][j];
        if (w == par[u])
          continue;
        par[w] = u;
        dep[w] = dep[u] + 1;
        ch[u].push_back(w);
        ord.push_back(w);
      }
    }

    long long S[n], D[n], mcs[n], bg[n];
    int fd[n];

    for (int i = n - 1; i >= 0; i--) {
      int v = ord[i];
      S[v] = a[v];
      D[v] = (long long)a[v] * dep[v];
      fd[v] = 0;
      mcs[v] = 0;
      bg[v] = 0;

      for (int j = 0; j < (int)ch[v].size(); j++) {
        int c = ch[v][j];
        S[v] += S[c];
        D[v] += D[c];
        if (fd[c] + 1 > fd[v])
          fd[v] = fd[c] + 1;
        if (S[c] > mcs[v])
          mcs[v] = S[c];
      }

      if (ch[v].empty())
        continue;

      int f1 = -1, f1c = -1, f2 = -1;
      for (int j = 0; j < (int)ch[v].size(); j++) {
        int c = ch[v][j];
        if (fd[c] > f1) {
          f2 = f1;
          f1 = fd[c];
          f1c = c;
        } else if (fd[c] > f2) {
          f2 = fd[c];
        }
      }

      for (int j = 0; j < (int)ch[v].size(); j++) {
        int c = ch[v][j];
        int be;
        if (c == f1c)
          be = 1 + f2;
        else
          be = 1 + f1;
        if (be < 0)
          be = 0;

        long long g = (long long)be * S[c];
        if (bg[c] > g)
          g = bg[c];
        long long tmp = (long long)(be - 1) * mcs[c];
        if (tmp > g)
          g = tmp;
        if (g > bg[v])
          bg[v] = g;
      }
    }

    for (int i = 0; i < n; i++) {
      long long base = D[i] - (long long)dep[i] * S[i];
      long long ans = base + bg[i];
      if (i > 0)
        cout << " ";
      cout << ans;
    }
    cout << endl;
  }
  return 0;
}
