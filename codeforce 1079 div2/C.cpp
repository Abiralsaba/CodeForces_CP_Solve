#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long p, q;
    cin >> p >> q;
    if (q > p && 2 * q <= 3 * p)
      cout << "Bob" << endl;
    else
      cout << "Alice" << endl;
  }
  return 0;
}
