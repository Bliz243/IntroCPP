#include <iostream>
#include <limits>

using namespace std;

// Simple recursive version
int fibonacci(int n) {
    if(n==0) return 1;
    if(n==1) return 1;
    return(fibonacci(n-1) + fibonacci(n-2));
}

// Optimised non-recursive version with memoization

// Global table to store precomputed Fibonacci numbers
#define MAXFIB 1000
int memo[MAXFIB];

int fibonacci_with_memo(int n){
    // First check if we have already computed the requested Fibonacci number
    if (memo[n] != -1) return memo[n];

    // Otherwise, compute the number and save the results in the table
    if (n == 0) {
        memo[0] = 1;
        return memo[0];
    }

    if (n == 1) {
        memo[1] = 1;
        return memo[1];
    }

    int f1 = fibonacci(n-1);
    int f2 = fibonacci(n-2);
    memo[n] = f1 + f2;
    return memo[n];
}

int main(void) {
    // Initialise the memoisation table
    // Only needed if we use fibonacci_with_memo() below
    for (int i = 0; i <= MAXFIB; i++) memo[i] = -1;

    int n;
    while (true) {
        cin >> n;
        if (cin.fail()) return 0;

        cout << fibonacci(n) << " ";
        // cout << fibonacci_with_memo(n) << " ";
    }

    return 0;
}
