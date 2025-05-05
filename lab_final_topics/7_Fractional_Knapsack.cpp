#include <bits/stdc++.h>
using namespace std;

struct Frac {
  int object;
  int profit;
  int weight;
  double PbW;
};

bool comparePbW(Frac &object1, Frac &object2) {
  if (object1.PbW > object2.PbW) return true;
  else return false;
}

int main() {
  int n, m; cin >> n >> m;
  Frac knapsack[n];
  int profit[n];
  for (int i = 0; i < n; i++) {
    knapsack[i].object = i;
    cin >> knapsack[i].profit;
    profit[i] = knapsack[i].profit;
  }

  for (int i = 0; i < n; i++) {
    cin >> knapsack[i].weight;
    knapsack[i].PbW = double(knapsack[i].profit) / double(knapsack[i].weight);
  }

  sort(knapsack, knapsack + n, comparePbW);

  double X[n];
  memset(X, 0.0, sizeof(X));

  int rw = m;
  int i = 0;

  while (rw > 0) {
    if (rw >= knapsack[i].weight) {
      X[knapsack[i].object] = 1;
      rw = rw - knapsack[i].weight;
    }
    else {
      X[knapsack[i].object] = double(rw) / double(knapsack[i].weight);
      rw = 0;
    }
    i++;
  }

  double maxProfit = 0;
  for (int i = 0; i < n; i++) {
    maxProfit = maxProfit + (X[i] * double(profit[i]));
  }

  cout << maxProfit << endl;
}