#include <iostream>
using namespace std;

void merging(int num[], int low, int mid, int high) {
  int m = mid - low + 1;
  int n = high - mid;
  int A[m], B[n];
  for (int i = 0; i < m; i++) A[i] = num[low + i];
  for (int j = 0; j < n; j++) B[j] = num[mid + 1 + j];

  int i = 0, j = 0, k = low;
  while (i < m && j < n) {
    if (A[i] > B[j]) {
      num[k] = B[j];
      j++;
      k++;
    }
    else {
      num[k] = A[i];
      i++;
      k++;
    }
  }
  for (; i < m; i++) {
    num[k] = A[i];
    k++;
  }
  for (; j < n; j++) {
    num[k] = B[j];
    k++;
  }
}

void mergeSort(int low, int high, int num[]) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    mergeSort(low, mid, num);
    mergeSort(mid + 1, high, num);
    merging(num, low, mid, high);
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  mergeSort(0, n - 1, arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}