#include <bits/stdc++.h> // include all header files
using namespace std;

// function to sort an array using insertion sort and print each step
void insertionSort(int n, int A[]) {
  for (int k = 0; k < n; k++) { // run a loop to print the initial array
    cout << A[k] << (k == n - 1 ? "\n" : " "); // output each element, with a newline at the end or a space otherwise
  }

  for (int i = 1; i < n; i++) { // run a loop starting from the second element
    int key = A[i]; // store the current element as key to be inserted
    int j = i - 1; // initialize j as the index before i to compare with previous elements

    while (j >= 0 && A[j] > key) { // run a while loop until j is valid and A[j] is greater than key
      A[j + 1] = A[j]; // shift the larger element one position ahead
      j--; // decrement j to check the next previous element
    }
    A[j + 1] = key; // insert key into its correct position

    for (int k = 0; k < n; k++) { // run a loop to print the array after this insertion
      cout << A[k] << (k == n - 1 ? "\n" : " "); // output each element, with a newline at the end or a space otherwise
    }
  }
}

// main function to execute the insertion sort program
int main() {
  ios::sync_with_stdio(false); // disable synchronization with C-style I/O for faster input/output
  cin.tie(0); // untie cin from cout to improve performance
  int n; // declare variable n to store the size of the array
  cin >> n; // input the size of the array from the user
  int arr[n]; // initialize array arr with size n
  for (int i = 0; i < n; i++) { // run a loop to input n elements
    cin >> arr[i]; // input each element into the array
  }
  insertionSort(n, arr); // call insertionSort to sort and print the array
  return 0; // exit the program
}