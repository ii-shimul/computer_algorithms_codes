#include <bits/stdc++.h>
using namespace std;

void insertionSort(int n, int A[]) {
  for (int k = 0; k < n; k++) {
    cout << A[k] << (k == n - 1 ? "\n" : " ");
  }

  for (int i = 1; i < n; i++) {
    int key = A[i];
    int j = i - 1;

    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;

    for (int k = 0; k < n; k++) {
      cout << A[k] << (k == n - 1 ? "\n" : " ");
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  insertionSort(n, arr);
  return 0;
}