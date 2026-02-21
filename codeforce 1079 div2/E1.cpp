#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> ans;
int dp[20];
bool vis[20];

vector<int> ask(int k) {
  cout << "? " << k << endl;
  int l;
  cin >> l;
  if (l == -1)
    exit(0);
  if (l == 0)
    return {};
  vector<int> p(l);
  for (int i = 0; i < l; i++)
    cin >> p[i];
  return p;
}

int solve(vector<int> p, int k, int d) {
  int u = p[d];
  if (vis[u])
    return dp[u];

  int res = 1;
  int cur = k + 1;

  while (true) {
    vector<int> np = ask(cur);
    if (np.empty() || np.size() <= d + 1)
      break;

    bool ok = true;
    for (int i = 0; i <= d; i++) {
      if (np[i] != p[i]) {
        ok = false;
        break;
      }
    }
    if (!ok)
      break;

    int v = np[d + 1];
    ans.push_back({u, v});

    int sub = solve(np, cur, d + 1);
    res += sub;
    cur += sub;
  }

  vis[u] = true;
  dp[u] = res;
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    ans.clear();
    for (int i = 0; i <= n; i++) {
      vis[i] = false;
      dp[i] = 0;
    }

    int k = 1;
    for (int i = 0; i < n; i++) {
      vector<int> p = ask(k);
      if (p.empty())
        break;
      int c = solve(p, k, 0);
      k += c;
    }

    cout << "! " << ans.size() << endl;
    for (auto x : ans) {
      cout << x.first << " " << x.second << endl;
    }
  }
  return 0;
}