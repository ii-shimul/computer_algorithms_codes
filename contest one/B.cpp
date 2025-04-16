#include <bits/stdc++.h> // include all header files
using namespace std;

// main function to perform run-length encoding on multiple input strings
int main() {
  ios::sync_with_stdio(false); // disable synchronization with C-style I/O for faster input/output
  cin.tie(0); // untie cin from cout to improve performance
  int t; cin >> t; // input the number of test cases
  while (t--) { // run a loop for each test case
    string s; cin >> s; // input the string for the current test case
    char current = s[0]; // initialize current as the first character of the string
    string result = ""; // initialize empty string result to store the encoded output
    int count = 1; // initialize count to 1 for the first character’s occurrence
    for (int i = 1; i <= s.size(); i++) { // run a loop from the second character to the end
      if (s[i] == current) { // if the current character matches the previous character
        count++; // increment count to track consecutive occurrences
      }
      else { // else a different character is encountered
        result += to_string(count) + s[i - 1]; // append the count and previous character to result
        count = 1; // reset count to 1 for the new character
        current = s[i]; // update current to the new character
      }
    }
    cout << result << endl; // output the encoded string followed by a newline
  }
  return 0; // exit the program
}