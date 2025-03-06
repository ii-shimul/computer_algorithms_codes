#include<bits/stdc++.h> // include all header files
using namespace std;

// structure to represent an item in the knapsack
struct sack {
  int object; // store the object’s index
  int profit; // store the profit of the object
  int weight; // store the weight of the object
  double pbw; // store the profit-to-weight ratio
};

// function to compare two sack items based on profit-to-weight ratio
bool comparePbW(sack& a1, sack& a2) {
  return a1.pbw > a2.pbw; // return true if a1’s ratio is greater than a2’s
}

// function to solve the knapsack problem using a greedy approach
double knapsackGreedy(int n, int m, sack frac[], double x[], int profits[]) {
  sort(frac, frac + n, comparePbW); // sort the array of items by profit-to-weight ratio in descending order

  memset(x, 0.0, sizeof(double) * n); // initialize the fraction array x with 0.0 for all n elements
  int rw = m; // initialize remaining weight capacity as m
  int i = 0; // initialize index i to track the current item
  double maxProfit = 0; // initialize maxProfit to store the total profit

  while (rw > 0 && i < n) { // run a while loop until capacity is exhausted or all items are considered
    if (rw >= frac[i].weight) { // if remaining weight can fully accommodate the current item
      rw -= frac[i].weight; // subtract the item’s weight from remaining capacity
      x[frac[i].object] = 1; // set the fraction of this item to 1 (fully taken)
      maxProfit += frac[i].profit; // add the item’s profit to maxProfit
    }
    else { // else remaining weight can only take a fraction of the item
      x[frac[i].object] = double(rw) / double(frac[i].weight); // calculate and set the fraction of the item taken
      maxProfit += x[frac[i].object] * frac[i].profit; // add the fractional profit to maxProfit
      rw = 0; // set remaining weight to 0 since capacity is now fully used
    }
    i++; // increment i to move to the next item
  }

  return maxProfit; // return the maximum profit achieved
}

// main function to execute the knapsack program
int main() {
  int t; cin >> t;
  while (t--)
  {
    int n, m; // declare n for number of items and m for knapsack capacity
    cin >> n >> m; // input the number of items and knapsack capacity
    sack frac[n]; // initialize array of sack structures with size n
    int profits[n]; // initialize array to store profits with size n
  
    for (int i = 0; i < n; i++) { // run a loop to input profits for n items
      frac[i].object = i; // assign the object index as i
      cin >> frac[i].profit; // input the profit for the current item
      profits[i] = frac[i].profit; // store the profit in the profits array
    }
    for (int i = 0; i < n; i++) { // run a loop to input weights and calculate ratios
      cin >> frac[i].weight; // input the weight for the current item
      frac[i].pbw = double(frac[i].profit) / double(frac[i].weight); // calculate profit-to-weight ratio
    }
  
    double x[n]; // initialize array x to store the fraction of each item taken
    double maxProfit = knapsackGreedy(n, m, frac, x, profits); // call knapsackGreedy to compute the maximum profit
  
    for (int i = 0; i < n; i++) { // run a loop to print the fraction of each item taken
      cout << x[i] << " "; // output the fraction followed by a space
    }
    cout << endl; // print a newline
    cout << maxProfit << endl; // output the maximum profit
  }
  return 0; // exit the program
}