#include<bits/stdc++.h> // include all header files
using namespace std;

// main function to calculate the length of the longest increasing subsequence
int main() {
  int n; // declare variable n to store the size of the array
  cin >> n; // input the size of the array
  int arr[n]; // initialize array arr with size n to store the input sequence
  for (int i = 0; i < n; i++) { // run a loop to input n elements
    cin >> arr[i]; // input each element into the array
  }

  int LIS[n]; // initialize array LIS with size n to store the length of LIS ending at each index
  for (int i = 0; i < n; i++) { // run a loop to initialize LIS array
    LIS[i] = 1; // set LIS[i] to 1 since each element is an increasing subsequence of length 1
  }

  for (int i = 1; i < n; i++) { // run a loop starting from the second element
    for (int j = 0; j < n; j++) { // run a nested loop over all previous elements
      if (arr[i] > arr[j]) { // if the current element is greater than a previous element
        LIS[i] = max(LIS[i], 1 + LIS[j]); // update LIS[i] to the maximum of its current value or 1 plus LIS[j]
      }
    }
  }

  int mx = INT_MIN; // initialize mx to the minimum integer value to find the maximum LIS length
  for (int i = 0; i < n; i++) { // run a loop through the LIS array
    if (mx < LIS[i]) // if the current LIS[i] is greater than mx
      mx = LIS[i]; // update mx to LIS[i]
  }
  cout << endl << mx << endl; // output a newline, the maximum LIS length, and another newline
}