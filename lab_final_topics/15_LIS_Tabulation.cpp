#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int list[n];
  for (int i = 0; i < n; i++) {
    cin >> list[i];
  }
  int LIS[n];

  for (int i = 0; i < n; i++) {
    LIS[i] = 1;
  }


  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (list[i] > list[j]) {
        LIS[i] = max(LIS[i], 1 + LIS[j]);
      }
    }
  }

  int mx = 1;
  for (int i = 0; i < n; i++) {
    if (LIS[i] > mx) {
      mx = LIS[i];
    }
  }
  cout << mx << endl;

}