#include <iostream>
using namespace std;

void insertionSort(int n, int num[]) {
  for (int i = 0; i < n; i++) {
    int x = num[i];
    int j = i - 1;
    while (j >= 0 && num[j] > x) {
      num[j + 1] = num[j];
      j--;
    }
    num[j + 1] = x;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  insertionSort(n, arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}