#include<bits/stdc++.h> // include all header files
using namespace std;

// function to sort an array using selection sort and count swaps
void SelectionSort(int A[], int n) {
  int ans = 0; // initialize variable to count the number of swaps
  for (int i = 0; i < n; i++) { // run a loop through the entire array
    int mini = i; // initialize mini as the index of the assumed minimum element
    for (int j = i; j < n; j++) { // run a nested loop from i to find the smallest element
      if (A[j] < A[mini]) { // if current element is smaller than the element at mini
        mini = j; // update mini to the index of the smaller element
      }
    }
    if (i != mini) { // if a smaller element was found
      swap(A[i], A[mini]); // swap the element at i with the smallest element
      ans++; // increment ans to track this swap
    }
  }
  for (int i = 0; i < n; i++) cout << A[i] << " \n"[i == n - 1]; // output each element, with a newline at the end or a space otherwise
  cout << ans << endl; // output the total number of swaps
}

// main function to execute the selection sort program
int main() {
  int n; // declare variable n to store the size of the array
  cin >> n; // input the size of the array from the user
  int A[n]; // initialize array A with size n
  for (int i = 0; i < n; i++) cin >> A[i]; // input each element into the array
  SelectionSort(A, n); // call SelectionSort to sort the array and print results
  return 0; // exit the program
}