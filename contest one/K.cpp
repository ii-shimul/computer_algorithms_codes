#include<bits/stdc++.h> // include all header files
using namespace std;

// function to sort an array using bubble sort and count swaps
void BubbleSort(int A[], int n) {
  int swap_count = 0; // initialize variable to count the number of swaps
  bool flag = 1; // initialize flag to track if any swaps occur in a pass
  while (flag) { // run a while loop until no swaps are needed
    flag = 0; // set flag to 0 to check if any swaps occur
    for (int j = n - 1; j > 0; j--) { // run a loop from the end to the second element
      if (A[j] < A[j - 1]) { // if current element is less than the previous element
        swap(A[j], A[j - 1]); // swap the two elements to place the smaller one earlier
        flag = 1; // set flag to 1 to indicate a swap occurred
        swap_count++; // increment swap_count to track this swap
      }
    }
  }
  for (int i = 0; i < n; i++) cout << A[i] << " \n"[i == n - 1]; // output each element, with a newline at the end or a space otherwise
  cout << swap_count << endl; // output the total number of swaps
}

// main function to execute the bubble sort program
int main() {
  int n; // declare variable n to store the size of the array
  cin >> n; // input the size of the array from the user
  int A[n]; // initialize array A with size n
  for (int i = 0; i < n; i++) cin >> A[i]; // input each element into the array
  BubbleSort(A, n); // call BubbleSort to sort the array and print results
  return 0; // exit the program
}