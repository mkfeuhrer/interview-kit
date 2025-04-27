#include <bits/stdc++.h>
using namespace std;

/*
 * Knapsack Problem
 * Returns the maximum value that can be obtained by selecting items from the given array.
 * Commonly used in dynamic programming problems.
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
*/

vector<int> dp; // dp[i] = maximum value that can be obtained with i capacity

int knapsack_memoization(vector<int>& weights, vector<int>& values, int capacity) {
    dp.assign(capacity + 1, -1);
    return knapsack_memoization_helper(weights, values, capacity);
}

int knapsack_memoization_helper(vector<int>& weights, vector<int>& values, int capacity) {
    if (capacity == 0) {
        return 0;
    }
    if (dp[capacity] != -1) {
        return dp[capacity];
    }
    int maxVal = 0;
    for (int i = 0; i < weights.size(); ++i) {
        if (weights[i] <= capacity) {
            maxVal = max(maxVal, values[i] + knapsack_memoization_helper(weights, values, capacity - weights[i]));
        }
    }
    dp[capacity] = maxVal;
    return maxVal;
}

int knapsack_tabulation(vector<int>& weights, vector<int>& values, int capacity) {
    dp.assign(capacity + 1, 0);
    for (int i = 1; i <= capacity; ++i) {
        for (int j = 0; j < weights.size(); ++j) {
            if (weights[j] <= i) {
                dp[i] = max(dp[i], dp[i - weights[j]] + values[j]);
            }
        }
    }
    return dp[capacity];
}

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> weights(n), values(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }
    cout << knapsack(weights, values, capacity) << endl;
    return 0;
}