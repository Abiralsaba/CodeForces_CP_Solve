#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, d;
    cin >> n >> m >> d;

    int max_in_tower = (d / m) + 1;
    int ans = (n + max_in_tower - 1) / max_in_tower;
    cout << ans << endl;
  }
  return 0;
}
