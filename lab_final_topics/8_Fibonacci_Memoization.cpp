#include <bits/stdc++.h>
using namespace std;

int fib(int n, int F[]) {
  if (F[n] != -1) return F[n];
  if (n <= 1) F[n] = n;
  else F[n] = fib(n - 2, F) + fib(n - 1, F);

  return F[n];
}

int main() {
  int n; cin >> n;
  int F[n + 1];
  memset(F, -1, sizeof(F));
  int ans = fib(n, F);
  cout << ans << endl;
}