#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int arr[n];
    int left = 1;
    int right = n;

    for (int i = n - 1; i >= 0; i--) {
      if ((n - 1 - i) % 2 == 0) {
        arr[i] = left;
        left++;
      } else {
        arr[i] = right;
        right--;
      }
    }

    for (int i = 0; i < n; i++) {
      if (i > 0)
        cout << " ";
      cout << arr[i];
    }
    cout << endl;
  }

  return 0;
}
