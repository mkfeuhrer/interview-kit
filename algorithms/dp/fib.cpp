#include <bits/stdc++.h>
using namespace std;

/*
 * Fibonacci Number
 * Returns the n-th Fibonacci number.
 * Commonly used in dynamic programming problems.
 * Time Complexity: O(n)
 * Space Complexity: O(n) (for memoization)
*/

vector<int> memo;

int fib_memo(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}

int fib_top_down(int n) {
    memo.assign(n + 1, -1);
    return fib_memo(n);
}

int fib_bottom_up(int n) {
    if (n <= 1) {
        return n;
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fib_space_optimized(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1;
    int c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b; // or c depending on loop end
}

int main() {
    int n;
    cin >> n;
    cout << fib_top_down(n) << endl;
    cout << fib_bottom_up(n) << endl;
    cout << fib_space_optimized(n) << endl;
    return 0;
}

