#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long x, y;
    cin >> x >> y;

    long long p = 0, q = 0;
    long long best = x + y;

    for (int i = 0; i < 32; i++) {
      long long bit = 1LL << i;
      long long lo = bit - 1;

      long long tp, tq, cost;

      tp = bit;
      tq = y & (~bit);
      cost = abs(x - tp) + abs(y - tq);
      if ((tp & tq) == 0 && cost < best) {
        best = cost;
        p = tp;
        q = tq;
      }

      tq = bit;
      tp = x & (~bit);
      cost = abs(x - tp) + abs(y - tq);
      if ((tp & tq) == 0 && cost < best) {
        best = cost;
        p = tp;
        q = tq;
      }

      tp = (x >> i) << i;
      if (y < bit)
        tq = y;
      else
        tq = lo;
      cost = abs(x - tp) + abs(y - tq);
      if ((tp & tq) == 0 && cost < best) {
        best = cost;
        p = tp;
        q = tq;
      }

      tp = ((x >> i) << i) + bit;
      if (y < bit)
        tq = y;
      else
        tq = lo;
      cost = abs(x - tp) + abs(y - tq);
      if ((tp & tq) == 0 && cost < best) {
        best = cost;
        p = tp;
        q = tq;
      }

      tq = (y >> i) << i;
      if (x < bit)
        tp = x;
      else
        tp = lo;
      cost = abs(x - tp) + abs(y - tq);
      if ((tp & tq) == 0 && cost < best) {
        best = cost;
        p = tp;
        q = tq;
      }

      tq = ((y >> i) << i) + bit;
      if (x < bit)
        tp = x;
      else
        tp = lo;
      cost = abs(x - tp) + abs(y - tq);
      if ((tp & tq) == 0 && cost < best) {
        best = cost;
        p = tp;
        q = tq;
      }
    }

    cout << p << " " << q << endl;
  }

  return 0;
}
