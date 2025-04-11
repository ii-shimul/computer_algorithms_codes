// my favourite
#include <bits/stdc++.h>
using namespace std;
int F[1000]; // initialize global array F to store Fibonacci values

// function to calculate nth Fibonacci number using memoization
int fibMemoization(int n) {
  if (n == 1 || n == 0) { // if n is 0 or 1 (base cases)
    F[n] = n; // set F[n] to n since fib(0) = 0 and fib(1) = 1
    return F[n]; // return the base case value
  }
  if (F[n] == -1) { // if F[n] has not been calculated yet
    F[n] = fibMemoization(n - 1) + fibMemoization(n - 2); // calculate F[n] as the sum of F[n-1] and F[n-2]
  }
  return F[n]; // return the calculated or stored Fibonacci value
}

// main function to execute the Fibonacci program
int main() {
  memset(F, -1, sizeof(F)); // set all elements of F to -1 to mark them as uncalculated
  int n; // declare variable n to store the input number
  cin >> n; // input the value of n from the user
  cout << fibMemoization(n); // output the nth Fibonacci number
}

//* Reason
/*
My journey to Dynamic Programming started with this small piece of code. To some, it is not that special of a code, but to me it is amazing.
When you, sir, explained this in class and came to the part of memoization with an array, so that we can save the repetitive calculations, I was
in shock actually! Such a simple idea, yet brilliant, at least it is to me. This simple idea reduces time complexity from O(2^n) to O(n)!
If n = 100, without DP it will take 1,267,650,600,228,229,401,496,703,205,376 calls, and with DP only 101 calls. It's amazing! It's awesome!
I have a little bit of regret for not exploring the DP world because of web development. But soon I am going to research it and quench my thirst.
*/