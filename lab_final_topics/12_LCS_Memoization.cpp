#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int memo[1000][1000];

int LCS(int i, int j) {
  if (s1[i] == '\0' || s1[j] == '\0') {
    return 0;
  }

  if (memo[i][j] != -1) {
    return memo[i][j];
  }

  if (s1[i] == s2[j]) {
    memo[i][j] = 1 + LCS(i + 1, j + 1);
  }
  else {
    memo[i][j] = max(LCS(i + 1, j), LCS(i, j + 1));
  }

  return memo[i][j];

}

int main() {
  getline(cin, s1);
  getline(cin, s2);
  memset(memo, -1, sizeof(memo));
  int ans = LCS(0, 0);
  cout << ans << endl;
  return 0;
}