#include<bits/stdc++.h> // include all header files
using namespace std;

// function to find the longest common subsequence between two strings
void lcs() {
  string s1, s2; // declare two strings s1 and s2 to store input
  getline(cin, s1); // input the first string from the user
  getline(cin, s2); // input the second string from the user
  int n = s1.size(); // store the length of s1 in n
  int m = s2.size(); // store the length of s2 in m
  int LCS[n + 1][m + 1]; // initialize 2D array LCS to store subsequence lengths

  for (int i = 0; i <= n; i++) { // run a loop over rows of LCS table
    for (int j = 0; j <= m; j++) { // run a nested loop over columns of LCS table
      if (i == 0 || j == 0) { // if either string is empty (base case)
        LCS[i][j] = 0; // set LCS[i][j] to 0 since no common subsequence exists
      }
      else if (s1[i - 1] == s2[j - 1]) { // if characters at i-1 and j-1 match
        LCS[i][j] = 1 + LCS[i - 1][j - 1]; // add 1 to the diagonal value for the match
      }
      else { // else characters don’t match
        LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]); // take the maximum of skipping s1 or s2 character
      }
    }
  }

  int length = LCS[n][m]; // store the length of the LCS from the bottom-right cell
  char sub[length + 1]; // initialize array sub to store the LCS characters
  sub[length] = '\0'; // set the last character as null to terminate the string

  int i = n, j = m, index = length - 1; // initialize i, j, and index to backtrack through the table
  while (i > 0 && j > 0) { // run a while loop until we reach the top or left edge
    if (s1[i - 1] == s2[j - 1]) { // if characters match
      sub[index] = s1[i - 1]; // add the matching character to the subsequence
      i--, j--, index--; // move diagonally up-left and decrement index
    }
    else if (LCS[i - 1][j] > LCS[i][j - 1]) { // if skipping s1 character gives a larger value
      i--; // move up in the table
    }
    else { // else skipping s2 character is better or equal
      j--; // move left in the table
    }
  }

  cout << "Length: " << length << endl; // output the length of the LCS
  cout << "Subsequence: " << sub << endl; // output the actual LCS string
}

// function to calculate the edit distance between two strings and show operations
void editDistance() {
  string s1, s2; // declare two strings s1 and s2 to store input
  cin.ignore(); // clear the input buffer before taking string input
  getline(cin, s1); // input the first string from the user
  getline(cin, s2); // input the second string from the user
  int m = s1.size(); // store the length of s1 in m
  int n = s2.size(); // store the length of s2 in n
  int EDIT[n + 1][m + 1]; // initialize 2D array EDIT to store edit distances

  for (int i = 0; i <= m; i++) EDIT[0][i] = i; // fill first row with costs to delete all of s1
  for (int i = 0; i <= n; i++) EDIT[i][0] = i; // fill first column with costs to insert all of s2

  for (int i = 1; i <= n; i++) { // run a loop over rows of EDIT table starting from 1
    for (int j = 1; j <= m; j++) { // run a nested loop over columns of EDIT table starting from 1
      if (s1[j - 1] == s2[i - 1]) { // if characters at j-1 and i-1 match
        EDIT[i][j] = EDIT[i - 1][j - 1]; // copy the diagonal value (no operation needed)
      }
      else { // else characters don’t match
        EDIT[i][j] = 1 + min({ EDIT[i - 1][j - 1], EDIT[i - 1][j], EDIT[i][j - 1] }); // add 1 to the minimum of replace, insert, or delete
      }
    }
  }

  cout << "Edit Distance: " << EDIT[n][m] << endl; // output the minimum edit distance

  int i = n, j = m; // initialize i and j to backtrack through the table
  while (i > 0 || j > 0) { // run a while loop until we reach the top-left corner
    if (i > 0 && j > 0 && s1[j - 1] == s2[i - 1]) { // if characters match
      i--, j--; // move diagonally up-left (no operation needed)
    }
    else if (i > 0 && EDIT[i][j] == 1 + EDIT[i - 1][j]) { // if insert operation was used
      cout << "Insert " << s2[i - 1] << endl; // output the insert operation
      i--; // move up in the table
    }
    else if (j > 0 && EDIT[i][j] == 1 + EDIT[i][j - 1]) { // if delete operation was used
      cout << "Delete " << s1[j - 1] << endl; // output the delete operation
      j--; // move left in the table
    }
    else if (i > 0 && j > 0) { // if replace operation was used
      cout << "Replace " << s1[j - 1] << " with " << s2[i - 1] << endl; // output the replace operation
      i--, j--; // move diagonally up-left
    }
  }
}

// main function to execute the program and choose between LCS and Edit Distance
int main() {
  char c; // declare variable c to store the user’s choice
  cout << "L - LCS\nE - Edit Distance\n"; // display the options to the user
  cin >> c; // input the user’s choice
  c = toupper(c); // convert the input to uppercase for consistency
  if (c == 'L') { // if user chooses L
    lcs(); // call the lcs function
  }
  else if (c == 'E') { // if user chooses E
    editDistance(); // call the editDistance function
  }
  else { // if user enters an invalid choice
    cout << "Invalid input!" << endl; // output an error message
  }
}