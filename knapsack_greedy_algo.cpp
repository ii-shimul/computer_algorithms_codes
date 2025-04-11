#include<bits/stdc++.h>
using namespace std;

struct sack {
  int object;
  int profit;
  int weight;
  double pbw;
};

bool comparePbW(sack& a1, sack& a2) {
  return a1.pbw > a2.pbw;
}

int main() {
  int n, m;
  cin >> n >> m;
  sack frac[n];
  int profits[n];
  for (int i = 0; i < n; i++) {
    frac[i].object = i;
    cin >> frac[i].profit;
    profits[i] = frac[i].profit;
  }
  for (int i = 0; i < n; i++) {
    cin >> frac[i].weight;
  }
  for (int i = 0; i < n; i++) {
    frac[i].pbw = double(frac[i].profit) / double(frac[i].weight);
  }
  sort(frac, frac + n, comparePbW);

  double x[n];
  memset(x, 0.0, sizeof(x));
  int rw = m;
  int i = 0;
  while (rw > 0) {
    if (rw >= frac[i].weight) {
      rw = rw - frac[i].weight;
      x[frac[i].object] = 1;
    }
    else {
      x[frac[i].object] = double(rw) / double(frac[i].weight);
      rw = 0;
    }
    i++;
  }
  for (int i = 0; i < n; i++) {
    cout << x[i] << " ";
  }
  cout << endl;
  double maxProfit = 0;
  for (int i = 0; i < n; i++) {
    maxProfit = maxProfit + (x[i] * double(profits[i]));
  }

  cout << maxProfit << endl;


  return 0;
}