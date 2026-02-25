#include <bits/stdc++.h>
using namespace std;

long long power(long long b, long long e) {
  long long r = 1;
  b %= 998244353;
  while (e > 0) {
    if (e % 2)
      r = (r * b) % 998244353;
    b = (b * b) % 998244353;
    e /= 2;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m;
  if (!(cin >> m))
    return 0;

  long long a[m], b_sort[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    b_sort[i] = a[i];
  }

  sort(b_sort, b_sort + m);

  long long sum_bit[m + 5];
  int count_bit[m + 5];
  for (int i = 0; i <= m; i++) {
    sum_bit[i] = count_bit[i] = 0;
  }

  auto add = [&](int i, long long v) {
    for (; i <= m; i += i & -i) {
      sum_bit[i] += v;
      count_bit[i]++;
    }
  };

  auto q_sum = [&](int i) {
    long long r = 0;
    for (; i > 0; i -= i & -i)
      r += sum_bit[i];
    return r;
  };

  auto find_k = [&](int k) {
    int p = 0;
    for (int i = 18; i >= 0; i--) {
      int nx = p + (1 << i);
      if (nx <= m && count_bit[nx] < k) {
        p = nx;
        k -= count_bit[p];
      }
    }
    return p + 1;
  };

  for (int i = 0; i < m; i++) {
    int rank = lower_bound(b_sort, b_sort + m, a[i]) - b_sort + 1;
    add(rank, a[i]);

    int sz = i + 1;
    if (sz < 3)
      continue;

    auto get_R = [&](int idx) {
      if (idx > sz)
        return 0LL;
      int p = find_k(idx);
      return (q_sum(m) - q_sum(p)) - 1LL * (sz - idx) * b_sort[p - 1];
    };

    auto get_L = [&](int idx) {
      if (idx < 1)
        return 0LL;
      int p = find_k(idx);
      return 1LL * (idx - 1) * b_sort[p - 1] - q_sum(p - 1);
    };

    int low = 1, high = sz, ans_k = sz;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (get_R(mid + 1) <= get_L(mid - 1)) {
        ans_k = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    long long best = max(get_R(ans_k + 1), get_L(ans_k - 1));
    if (ans_k > 1) {
      best = min(best, max(get_R(ans_k), get_L(ans_k - 2)));
    }

    cout << (best % 998244353) * power(sz - 2, 998244353 - 2) % 998244353
         << "\n";
  }

  return 0;
}
