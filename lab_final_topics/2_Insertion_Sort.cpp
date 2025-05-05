#include <bits/stdc++.h>
using namespace std;

void insertionSort(int n, int arr[]) {
  for (int i = 0; i < n; i++) {
    int x = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > x) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = x;
  }
}

int main() {
  int n; cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  insertionSort(n, arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}