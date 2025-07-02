#include "Fibonacci.h"
#include <iostream>

// Memoization (Top-down)
long long fibonacci_memoization(int n, std::vector<long long>& memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonacci_memoization(n - 1, memo) + fibonacci_memoization(n - 2, memo);
    return memo[n];
}

// Tabulation (Bottom-up)
long long fibonacci_tabulation(int n) {
    if (n <= 1) {
        return n;
    }
    std::vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
