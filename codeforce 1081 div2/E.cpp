#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
vector<pair<int, int>> adj[N];
bool vis[N];
int freq[N];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      freq[i] = 0;
      vis[i] = false;
    }

    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      freq[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      freq[b[i]]++;
    }

    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (freq[i] % 2 != 0) {
        ok = false;
        break;
      }
    }

    if (!ok) {
      cout << -1 << endl;
      continue;
    }

    for (int i = 1; i <= n; i++) {
      adj[a[i]].push_back({b[i], i});
      adj[b[i]].push_back({a[i], i});
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (adj[i].empty())
        continue;

      vector<int> st;
      st.push_back(i);
      while (!st.empty()) {
        int u = st.back();
        if (adj[u].empty()) {
          st.pop_back();
        } else {
          pair<int, int> edge = adj[u].back();
          adj[u].pop_back();
          int v = edge.first;
          int id = edge.second;

          if (vis[id])
            continue;

          vis[id] = true;
          if (a[id] != u) {
            ans.push_back(id);
          }
          st.push_back(v);
        }
      }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
      if (i > 0)
        cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}
