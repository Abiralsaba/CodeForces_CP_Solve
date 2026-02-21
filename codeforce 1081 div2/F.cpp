
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long INV2 = 500000004;

int n, x, y;
long long a[3005], b[3005], pre[3005];
unordered_map<long long, long long> memo;

long long pk(int lx, int rx, int ly, int ry, int turn) {
  return ((long long)lx << 38) | ((long long)rx << 26) | ((long long)ly << 14) | ((long long)ry << 2) | turn;
}

long long gsz(int l, int r, int orig) {
  long long sm = pre[r] - (l > 0 ? pre[l - 1] : 0);
  return a[orig] + sm - b[orig];
}

long long dp(int lx, int rx, int ly, int ry, int turn) {
  if (lx <= y && y <= rx)
    return 1;
  if (ly <= x && x <= ry)
    return 0;

  long long key = pk(lx, rx, ly, ry, turn);
  if (memo.count(key))
    return memo[key];

  if (turn == 0) {
    long long cx = gsz(lx, rx, x);
    long long cy = gsz(ly, ry, y);

    bool canL = false;
    bool canR = false;
    if (lx > 0) {
      int e = lx - 1;
      long long target = (ly <= e && e <= ry) ? cy : a[e];
      if (cx >= target)
        canL = true;
    }
    if (rx < n - 1) {
      int e = rx + 1;
      long long target = (ly <= e && e <= ry) ? cy : a[e];
      if (cx >= target)
        canR = true;
    }

    int ops = (canL ? 1 : 0) + (canR ? 1 : 0);
    if (ops == 0)
      return memo[key] = 0;

    long long p = 0;
    if (canL) {
      if (ly <= lx - 1 && lx - 1 <= ry)
        p = (p + 1) % MOD;
      else
        p = (p + dp(lx - 1, rx, ly, ry, 1)) % MOD;
    }
    if (canR) {
      if (ly <= rx + 1 && rx + 1 <= ry)
        p = (p + 1) % MOD;
      else
        p = (p + dp(lx, rx + 1, ly, ry, 1)) % MOD;
    }

    return memo[key] = (ops == 1) ? p : p * INV2 % MOD;
  } else {
    long long cx = gsz(lx, rx, x);
    long long cy = gsz(ly, ry, y);

    bool canL = false;
    bool canR = false;
    if (ly > 0) {
      int e = ly - 1;
      long long target = (lx <= e && e <= rx) ? cx : a[e];
      if (cy >= target)
        canL = true;
    }
    if (ry < n - 1) {
      int e = ry + 1;
      long long target = (lx <= e && e <= rx) ? cx : a[e];
      if (cy >= target)
        canR = true;
    }

    int ops = (canL ? 1 : 0) + (canR ? 1 : 0);
    if (ops == 0)
      return memo[key] = 1;

    long long p = 0;
    if (canL && !(lx <= ly - 1 && ly - 1 <= rx))
      p = (p + dp(lx, rx, ly - 1, ry, 0)) % MOD;
    if (canR && !(lx <= ry + 1 && ry + 1 <= rx))
      p = (p + dp(lx, rx, ly, ry + 1, 0)) % MOD;

    return memo[key] = (ops == 1) ? p : p * INV2 % MOD;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    x--;
    y--;

    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];

    for (int i = 0; i < n; i++)
      pre[i] = b[i] + (i > 0 ? pre[i - 1] : 0);

    memo.clear();

    cout << dp(x, x, y, y, 0) << endl;
  }
  return 0;
}
