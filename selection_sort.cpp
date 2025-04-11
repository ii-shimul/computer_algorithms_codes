#include <iostream>
using namespace std;

void selectionSort(int n, int num[]) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (num[i] > num[j]) {
        swap(num[i], num[j]);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  selectionSort(n, arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}