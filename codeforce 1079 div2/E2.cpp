#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> ans;
int dp[40];
bool vis[40];
vector<int> rem;

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
    vector<int> np;
    if (!rem.empty()) {
      np = rem;
      rem.clear();
    } else {
      np = ask(cur);
    }

    if (np.empty())
      break;

    if (np.size() <= d + 1) {
      rem = np;
      break;
    }

    bool ok = true;
    for (int i = 0; i <= d; i++) {
      if (np[i] != p[i]) {
        ok = false;
        break;
      }
    }

    if (!ok) {
      rem = np;
      break;
    }

    ans.push_back({u, np[d + 1]});
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
    rem.clear();

    int k = 1;
    for (int i = 1; i <= n; i++) {
      vector<int> p;
      if (!rem.empty()) {
        p = rem;
        rem.clear();
      } else {
        p = {i};
      }

      if (p.empty())
        break;

      if (p[0] == i) {
        int c = solve(p, k, 0);
        k += c;
      } else {
        rem = p;
      }
    }

    cout << "! " << ans.size() << endl;
    for (auto x : ans) {
      cout << x.first << " " << x.second << endl;
    }
  }
  return 0;
}
