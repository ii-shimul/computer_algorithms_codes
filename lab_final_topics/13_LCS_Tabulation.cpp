#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  int n = s1.size();
  int m = s2.size();

  int LCS[n + 1][m + 1];
  for (int i = 0; i < n + 1; i++) {
    LCS[i][0] = 0;
  }
  for (int i = 0; i < m + 1; i++) {
    LCS[0][i] = 0;
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        LCS[i][j] = LCS[i - 1][j - 1] + 1;
      }
      else {
        LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
      }
    }

  }
  cout << LCS[n][m] << endl;

  int i = n, j = m;
  string ans;

  while (i > 0) {
    if (LCS[i][j] == 1 + LCS[i - 1][j - 1] && s1[i - 1] == s2[j - 1]) {
      ans = s2[j - 1] + ans;
      i = i - 1;
      j = j - 1;
    }
    else {
      if (LCS[i][j] == LCS[i - 1][j]) {
        i = i - 1;
      }
      else {
        j = j - 1;
      }
    }
  }
  
  cout<<ans<<endl;

}