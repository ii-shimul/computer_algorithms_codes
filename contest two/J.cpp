#include<bits/stdc++.h>
using namespace std;

int main() {
  int n = 5, m;
  cin >> m;
  int coins[n] = { 50, 25, 10, 5, 1 };

  long long int change[n + 1][m + 1];

  // Initialize
  for (int i = 1; i < m + 1; i++) {
    change[0][i] = -1; // -1 means impossible
  }
  for (int i = 0; i < n + 1; i++) {
    change[i][0] = 0; // 0 coins needed for amount 0
  }

  // Fill DP table
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (coins[i - 1] > j) {
        change[i][j] = change[i - 1][j];
      }
      else {
        if (change[i][j - coins[i - 1]] != -1) {
          change[i][j] = max(change[i - 1][j], 1 + change[i][j - coins[i - 1]]);
        }
        else {
          change[i][j] = change[i - 1][j];
        }
      }
    }
  }

  // Output result
  if (change[n][m] == -1) {
    cout << "No combination possible" << endl;
  }
  else {
    cout << "Maximum coins used: " << change[n][m] << endl;
    cout << "Combination: ";

    int i = n, j = m;
    while (i > 0 && j > 0) {
      if (change[i][j] == change[i - 1][j]) {
        i--;
      }
      else {
        cout << coins[i - 1] << " ";
        j -= coins[i - 1];
      }
    }
    cout << endl;
  }

  return 0;
}