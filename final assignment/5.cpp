#include<bits/stdc++.h> 
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int LIS[n];
  for (int i = 0; i < n; i++) {
    LIS[i] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i] > arr[j]) {
        LIS[i] = max(LIS[i], 1 + LIS[j]);
      }
    }
  }

  int mx = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (mx < LIS[i])
      mx = LIS[i];
  }
  cout << endl << mx << endl;
}