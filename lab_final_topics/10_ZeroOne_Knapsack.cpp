#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int profit[n];
  int weight[n];
  for (int i = 0; i < n; i++) {
    cin >> profit[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  int ZO[n + 1][m + 1];

  for (int i = 0; i < n + 1; i++) {
    ZO[i][0] = 0;
  }
  for (int i = 0; i < m + 1; i++) {
    ZO[0][i] = 0;
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (weight[i - 1] > j) {
        ZO[i][j] = ZO[i - 1][j];
      }
      else {
        ZO[i][j] = max(ZO[i - 1][j], profit[i - 1] + ZO[i - 1][j - weight[i - 1]]);
      }
    }
  }

  int i = n, j = m;
  while (i > 0) {
    if (ZO[i][j] == ZO[i - 1][j]) {
      i--;
    }
    else {
      cout << i << " selected" << endl;
      i = i - 1;
      j = j - weight[i];
    }
  }
}