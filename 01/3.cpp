#include<bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  int m = s1.size();
  int n = s2.size();
  int EDIT[n + 1][m + 1];

  for (int i = 0; i < m + 1; i++) {
    EDIT[0][i] = i;
  }
  for (int i = 0; i < n + 1; i++) {
    EDIT[i][0] = i;
  }


  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (s1[j - 1] == s2[i - 1]) {
        EDIT[i][j] = EDIT[i - 1][j - 1];
      }
      else {
        EDIT[i][j] = 1 + min({ EDIT[i - 1][j - 1], EDIT[i - 1][j], EDIT[i][j - 1] });
      }
    }
  }


  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < m + 1; j++) {
      cout << EDIT[i][j] << " ";
    }
    cout << endl;
  }

  int i = n, j = m;
  while (i > 0) {
    if (s1[j - 1] == s2[i - 1]) {
      i = i - 1;
      j = j - 1;
    }
    else {
      if (EDIT[i][j] == 1 + EDIT[i - 1][j]) {
        cout << s1[j - 1] << " is inserted" << endl;
        i = i - 1;
      }
      else if (EDIT[i][j] == 1 + EDIT[i][j - 1]) {
        cout << s1[j - 1] << " is deleted" << endl;
        j = j - 1;
      }
      else {
        cout << s1[j - 1] << " is replaced to " << s2[i - 1] << endl;
        i = i - 1;
        j = j - 1;
      }
    }
  }
}