#include <bits/stdc++.h> // include all header files
using namespace std;

// function to sort an array using counting sort
void CountingSort(int A[], int n, int k) {
  int C[k + 1] = { 0 }; // initialize array C with size k+1 to count occurrences, all set to 0
  int B[n]; // initialize array B with size n to store the sorted output
  for (int j = 0; j < n; j++) C[A[j]]++; // count the occurrences of each element in A

  for (int i = 1; i <= k; i++) C[i] += C[i - 1]; // compute cumulative counts to determine positions

  for (int j = n - 1; j >= 0; j--) { // run a loop backward through A to maintain stable sorting
    B[C[A[j]] - 1] = A[j]; // place A[j] in its correct position in B based on cumulative count
    C[A[j]]--; // decrement the count for A[j] to handle duplicates
  }

  for (int i = 0; i < n; i++) { // run a loop to copy sorted elements back to A
    A[i] = B[i]; // copy each element from B to A
  }
}

// main function to execute the counting sort program
int main() {
  ios::sync_with_stdio(false); // disable synchronization with C-style I/O for faster input/output
  cin.tie(0); // untie cin from cout to improve performance
  int n; cin >> n; // input the size of the array from the user
  int A[n]; // initialize array A with size n
  for (int i = 0; i < n; i++) cin >> A[i]; // input each element into the array
  int k = *max_element(A, A + n); // find the maximum element in A to determine the range for counting
  CountingSort(A, n, k); // call CountingSort to sort the array
  for (int i = 0; i < n; i++) { // run a loop to print the sorted array
    cout << A[i] << (i == n - 1 ? "\n" : " "); // output each element followed by a space
  }
  return 0; // exit the program
}