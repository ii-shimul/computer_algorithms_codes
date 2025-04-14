#include <bits/stdc++.h> // include all header files
using namespace std;
int comparisons = 0; // declare global variable to count comparisons

// function to merge two sorted subarrays into one sorted array
void Merge(int A[], int left, int mid, int right) {
  int n1 = mid - left; // calculate the size of the left subarray
  int n2 = right - mid; // calculate the size of the right subarray
  int L[n1 + 1], R[n2 + 1]; // initialize arrays L and R to hold left and right subarrays
  for (int i = 0; i < n1; i++) L[i] = A[left + i]; // copy elements from A[left] to A[mid-1] into L
  for (int i = 0; i < n2; i++) R[i] = A[mid + i]; // copy elements from A[mid] to A[right-1] into R

  L[n1] = INT_MAX; // set sentinel value at the end of L to avoid bounds checking
  R[n2] = INT_MAX; // set sentinel value at the end of R to avoid bounds checking

  int i = 0, j = 0; // initialize indices i and j to track positions in L and R

  for (int k = left; k < right; k++) { // run a loop to merge elements back into A
    if (L[i] <= R[j]) { // if element in L is less than or equal to element in R
      A[k] = L[i]; // place L[i] into A[k]
      i++; // increment i to move to the next element in L
      comparisons++; // increment comparisons counter
    }
    else { // else element in R is smaller
      A[k] = R[j]; // place R[j] into A[k]
      j++; // increment j to move to the next element in R
      comparisons++; // increment comparisons counter
    }
  }
}

// function to sort an array using merge sort
void MergeSort(int A[], int left, int right) {
  if (left + 1 < right) { // if there are at least two elements to sort
    int mid = (left + right) / 2; // calculate the middle index
    MergeSort(A, left, mid); // recursively sort the left half
    MergeSort(A, mid, right); // recursively sort the right half
    Merge(A, left, mid, right); // merge the sorted halves
  }
}

// main function to execute the merge sort program
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n; // declare variable n to store the size of the array
  cin >> n; // input the size of the array
  int A[n]; // initialize array A with size n
  for (int i = 0; i < n; i++) { // run a loop to input n elements
    cin >> A[i]; // input each element into the array
  }
  MergeSort(A, 0, n); // call MergeSort to sort the array from index 0 to n
  for (int i = 0; i < n; i++) { // run a loop to print the sorted array
    if (i == n - 1) {
      cout << A[i] << endl; // output each element
    }
    else {
      cout << A[i] << " "; // output each element followed by a space
    }
  }
  cout << comparisons << endl; // output the number of comparisons
  return 0;
}