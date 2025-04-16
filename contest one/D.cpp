#include <bits/stdc++.h> // include all header files
using namespace std;

// main function to calculate the maximum number of teams
int main() {
  ios::sync_with_stdio(false); // disable synchronization with C-style I/O for faster input/output
  cin.tie(0); // untie cin from cout to improve performance
  int n, k; cin >> n >> k; // input n and k
  int arr[n]; // initialize array arr with size n to store each student’s past participation's
  for (int i = 0; i < n; i++) { // run a loop to input n participation counts
    cin >> arr[i]; // input the number of past participation's for the i-th student
    arr[i] += k; // add k to the student’s participation count to account for future participation's
  }
  int count = 0; // initialize count to track students eligible to participate
  for (int i = 0; i < n; i++) { // run a loop through the array
    if (arr[i] <= 5) count++; // increment count if the student’s adjusted participation count is <= 5
  }
  cout << count / 3 << endl; // output the maximum number of teams by dividing eligible students by 3
}