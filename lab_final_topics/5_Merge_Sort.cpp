#include <bits/stdc++.h>
using namespace std;

void merging(int low, int mid, int high, int arr[]) {
  int m = mid - low + 1;
  int n = high - mid;
  int A[m];
  int B[n];
  for (int i = 0; i < m; i++) {
    A[i] = arr[low + i];
  }
  for (int j = 0; j < n; j++) {
    B[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = low;
  while (i < m && j < n) {
    if (A[i] < B[j]) {
      arr[k] = A[i];
      k++; i++;
    }
    else {
      arr[k] = B[j];
      k++; j++;
    }
  }

  for (; i < m; i++) {
    arr[k] = A[i]; k++;
  }
  for (; j < n; j++) {
    arr[k] = B[j]; k++;
  }
}

void mergeSort(int low, int high, int arr[]) {
  if (low >= high) {
    return;
  }

  int mid = (low + high) / 2;
  mergeSort(low, mid, arr);
  mergeSort(mid + 1, high, arr);
  merging(low, mid, high, arr);

}

int main() {
  int n; cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  mergeSort(0, n - 1, arr);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}