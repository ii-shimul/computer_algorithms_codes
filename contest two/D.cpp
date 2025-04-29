#include <bits/stdc++.h> // include all header files
using namespace std;

// main function to calculate the edit distance between two strings across multiple test cases
int main() {
  ios_base::sync_with_stdio(false); // disable synchronization with C-style I/O for faster input/output
  cin.tie(NULL); // untie cin from cout to improve performance

  int t; // declare variable t to store the number of test cases
  cin >> t; // input the number of test cases
  cin.ignore(); // clear the input buffer to handle newline after t before getline

  while (t--) { // run a loop for each test case
    string s1, s2; // declare two strings s1 and s2 to store input
    getline(cin, s1); // input the first string s1 from the user
    getline(cin, s2); // input the second string s2 from the user

    int m = s1.size(); // store the length of s1 in m
    int n = s2.size(); // store the length of s2 in n

    int EDIT[m + 1][n + 1]; // initialize 2D array EDIT to store edit distances, size (m+1) x (n+1)

    for (int i = 0; i <= m; i++) // run a loop to initialize the first column
      EDIT[i][0] = i; // set EDIT[i][0] to i as the cost to delete all characters of s1
    for (int j = 0; j <= n; j++) // run a loop to initialize the first row
      EDIT[0][j] = j; // set EDIT[0][j] to j as the cost to insert all characters of s2

    for (int i = 1; i <= m; i++) { // run a loop over rows of EDIT table starting from 1
      for (int j = 1; j <= n; j++) { // run a nested loop over columns of EDIT table starting from 1
        if (s1[i - 1] == s2[j - 1]) { // if characters at i-1 in s1 and j-1 in s2 match
          EDIT[i][j] = EDIT[i - 1][j - 1]; // copy the diagonal value since no operation is needed
        }
        else { // else characters don’t match
          EDIT[i][j] = 1 + min({ EDIT[i - 1][j], EDIT[i][j - 1], EDIT[i - 1][j - 1] }); // add 1 to the minimum of insert, delete, or replace
        }
      }
    }

    cout << EDIT[m][n] << endl; // output the minimum edit distance for this test case
  }
  return 0; // exit the program
}