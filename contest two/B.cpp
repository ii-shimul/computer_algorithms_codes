#include<bits/stdc++.h> // include all header files
using namespace std;

// main function to calculate the length of the longest common subsequence between two strings
int main() {
  string s1, s2; // declare two strings s1 and s2 to store input
  cin >> ws;
  getline(cin, s1);
  cin >> ws;
  getline(cin, s2);
  int n = s1.size(); // store the length of s1 in n
  int m = s2.size(); // store the length of s2 in m

  int LCS[n + 1][m + 1]; // initialize 2D array LCS to store subsequence lengths, size (n+1) x (m+1)
  for (int i = 0; i < n + 1; i++) { // run a loop to initialize the first column
    LCS[i][0] = 0; // set LCS[i][0] to 0 since no common subsequence exists with an empty s2
  }
  for (int i = 0; i < m + 1; i++) { // run a loop to initialize the first row
    LCS[0][i] = 0; // set LCS[0][i] to 0 since no common subsequence exists with an empty s1
  }

  for (int i = 1; i < n + 1; i++) { // run a loop over rows of LCS table starting from 1
    for (int j = 1; j < m + 1; j++) { // run a nested loop over columns of LCS table starting from 1
      if (s1[i - 1] == s2[j - 1]) { // if characters at i-1 in s1 and j-1 in s2 match
        LCS[i][j] = 1 + LCS[i - 1][j - 1]; // add 1 to the diagonal value for the match
      }
      else { // else characters don’t match
        LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]); // take the maximum of skipping s1 or s2 character
      }
    }
  }
  cout << LCS[n][m] << endl; // output the length of the LCS stored in the bottom-right cell
}