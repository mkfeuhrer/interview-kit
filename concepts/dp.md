# Introduction to Dynamic Programming

Dynamic Programming is an algorithmic technique used to solve problems that have:

1.  **Overlapping Subproblems:** The same subproblems are encountered and solved multiple times during a recursive solution.
2.  **Optimal Substructure:** An optimal solution to the problem can be constructed from optimal solutions to its subproblems.

When these two properties are present, a naive recursive solution will often be inefficient due to redundant computations. DP avoids this by storing the results of subproblems so they can be reused later.

### 2. Key Concepts: Memoization vs. Tabulation

There are two main approaches to implementing Dynamic Programming:

- **Memoization (Top-Down DP):** This is essentially recursion with caching. You write a recursive function but store the result of each subproblem computation in a cache (like an array or map). Before computing a subproblem, you check if its result is already in the cache. If yes, return the cached value; otherwise, compute it and store it in the cache before returning.

  - **Pros:** Often more intuitive as it directly follows the recursive definition. Only computes necessary subproblems.
  - **Cons:** Can lead to stack overflow issues for deep recursion. Overhead of recursive calls.

- **Tabulation (Bottom-Up DP):** This approach solves the subproblems iteratively, typically filling up a DP table (usually an array or multi-dimensional array). You start from the base cases and build up solutions for larger subproblems using the results of smaller, already-solved subproblems.
  - **Pros:** No recursion overhead, avoids stack overflow. Can sometimes be easier to reason about space optimization.
  - **Cons:** Requires careful ordering of subproblems to ensure dependencies are met. Might compute some subproblems that are not strictly necessary for the final answer.

Both approaches yield the same result and complexity (in terms of the number of unique subproblems), but the implementation style differs.

### 3. Steps to Solve a DP Problem

1.  **Identify if it's a DP problem:** Look for overlapping subproblems and optimal substructure. Can the problem be broken down into smaller, similar subproblems? Does solving these subproblems optimally help solve the larger problem optimally?
2.  **Define the State:** What are the parameters that uniquely define a subproblem? This will often correspond to the indices in your DP table or the arguments to your memoized recursive function. For example, `dp[i]` might be the solution for the first `i` elements, or `dp[i][j]` might be the solution considering elements from index `i` to `j`.
3.  **Define the Base Cases:** What are the simplest subproblems whose solutions are known directly without further recursion/computation? These are the starting points for your DP.
4.  **Define the Recurrence Relation:** How can you compute the solution for a given state (subproblem) using the solutions of smaller states? This is the core of the DP algorithm. It expresses the relationship between the current problem and its subproblems.
5.  **Choose Memoization or Tabulation:** Decide on your implementation approach.
6.  **Implement and Optimize:** Write the code. If using tabulation, determine the correct iteration order. Consider space optimization if possible (if the current state only depends on a few previous states, you might not need the entire DP table).

### 4. Examples with C++ Code

Let's illustrate with classic DP problems.

#### Example 1: Fibonacci Sequence

- **Problem:** Calculate the N-th Fibonacci number. F(N) = F(N-1) + F(N-2), with F(0) = 0, F(1) = 1.
- **Overlapping Subproblems:** Calculating F(5) requires F(4) and F(3). F(4) requires F(3) and F(2). F(3) is computed twice.
- **Optimal Substructure:** F(N) is directly defined by F(N-1) and F(N-2).
- **State:** `dp[i]` represents the i-th Fibonacci number.
- **Base Cases:** `dp[0] = 0`, `dp[1] = 1`.
- **Recurrence Relation:** `dp[i] = dp[i-1] + dp[i-2]` for i > 1.

**C++ Code (Memoization - Top-Down):**

```cpp
#include <vector>
#include <iostream>

std::vector<int> memo;

int fib_memo(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) { // Check if already computed
        return memo[n];
    }
    // Compute and store
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}

int fib_top_down(int n) {
    memo.assign(n + 1, -1); // Initialize memoization table with -1 (or another indicator)
    return fib_memo(n);
}

// Example usage:
// std::cout << fib_top_down(10) << std::endl; // Output: 55
```

**C++ Code (Tabulation - Bottom-Up):**

```cpp
#include <vector>
#include <iostream>

int fib_bottom_up(int n) {
    if (n <= 1) {
        return n;
    }
    std::vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Example usage:
// std::cout << fib_bottom_up(10) << std::endl; // Output: 55
```

**Space Optimization for Fibonacci:**

Notice that `dp[i]` only depends on `dp[i-1]` and `dp[i-2]`. We only need to keep track of the last two values, not the entire DP table.

```cpp
#include <iostream>

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

// Example usage:
// std::cout << fib_space_optimized(10) << std::endl; // Output: 55
```

#### Example 2: Climbing Stairs

- **Problem:** You are climbing a staircase. It takes `n` steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
- **Overlapping Subproblems:** To reach step `n`, you must have come from step `n-1` or step `n-2`. The number of ways to reach `n` is the sum of ways to reach `n-1` and ways to reach `n-2`. This is the Fibonacci recurrence!
- **Optimal Substructure:** The number of ways to reach the top depends on the number of ways to reach previous steps.
- **State:** `dp[i]` represents the number of distinct ways to reach step `i`.
- **Base Cases:** `dp[0] = 1` (one way to reach step 0 - do nothing), `dp[1] = 1` (one way to reach step 1 - take 1 step).
- **Recurrence Relation:** `dp[i] = dp[i-1] + dp[i-2]` for i > 1.

**C++ Code (Tabulation - Bottom-Up):**

```cpp
#include <vector>
#include <iostream>

int climbStairs(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;

    std::vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// This can also be space optimized like Fibonacci.
// Example usage:
// std::cout << climbStairs(5) << std::endl; // Output: 8 (1,1,1,1,1; 1,1,1,2; 1,1,2,1; 1,2,1,1; 2,1,1,1; 1,2,2; 2,1,2; 2,2,1)
```

#### Example 3: Coin Change (Minimum Coins)

- **Problem:** Given a set of coin denominations and a target amount, find the minimum number of coins needed to make up that amount. If the amount cannot be made, return -1. Assume you have an infinite supply of each coin.
- **Overlapping Subproblems:** To find the minimum coins for amount `A`, you consider using each coin `c`. The remaining amount is `A-c`. The minimum coins for `A` is 1 (for coin `c`) plus the minimum coins for `A-c`. The subproblem for `A-c` might be needed for different initial coins `c`.
- **Optimal Substructure:** The optimal solution for amount `A` is based on the optimal solutions for smaller amounts `A-c`.
- **State:** `dp[i]` represents the minimum number of coins needed to make amount `i`.
- **Base Cases:** `dp[0] = 0` (0 coins needed for amount 0). For all other `i > 0`, initialize `dp[i]` to infinity (a very large number) to indicate that the amount is not yet reachable.
- **Recurrence Relation:** `dp[i] = min(dp[i], dp[i - coin] + 1)` for each `coin` in denominations, where `i >= coin`. We iterate through each coin denomination and update `dp[i]` if using that coin provides a better solution.

**C++ Code (Tabulation - Bottom-Up):**

```cpp
#include <vector>
#include <algorithm> // For std::min
#include <limits>    // For std::numeric_limits
#include <iostream>

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            // If the current amount i is greater than or equal to the coin value
            // and the subproblem dp[i - coin] is reachable (not infinity)
            if (i >= coin && dp[i - coin] != std::numeric_limits<int>::max()) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] is still infinity, it means the amount is not reachable
    return dp[amount] == std::numeric_limits<int>::max() ? -1 : dp[amount];
}

// Example usage:
// std::vector<int> coins = {1, 2, 5};
// int amount = 11;
// std::cout << coinChange(coins, amount) << std::endl; // Output: 3 (5 + 5 + 1)
// coins = {2}; amount = 3;
// std::cout << coinChange(coins, amount) << std::endl; // Output: -1
```

#### Example 4: Longest Increasing Subsequence (LIS)

- **Problem:** Given an array of integers, find the length of the longest increasing subsequence. A subsequence is formed by deleting zero or more elements from the original array while maintaining the relative order of the remaining elements.
- **Overlapping Subproblems:** To find LIS ending at index `i`, you look at all previous indices `j < i`. If `nums[i] > nums[j]`, you can potentially extend the LIS ending at `j` by including `nums[i]`. The LIS ending at `i` is 1 plus the maximum LIS ending at any such `j`.
- **Optimal Substructure:** The length of the LIS ending at a particular index depends on the lengths of LIS ending at previous indices.
- **State:** `dp[i]` represents the length of the longest increasing subsequence _ending at_ index `i`.
- **Base Cases:** `dp[i] = 1` for all `i` (an increasing subsequence of length 1 consists of just the element itself).
- **Recurrence Relation:** For each `i` from 1 to n-1, `dp[i] = 1 + max(dp[j])` for all `j < i` such that `nums[i] > nums[j]`. If no such `j` exists, `dp[i]` remains 1. The final answer is the maximum value in the `dp` array.

**C++ Code (Tabulation - Bottom-Up - O(N^2)):**

```cpp
#include <vector>
#include <algorithm> // For std::max
#include <iostream>

int lengthOfLIS(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    std::vector<int> dp(n, 1); // dp[i] = length of LIS ending at index i
    int maxLength = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            // If nums[i] can extend the LIS ending at j
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        maxLength = std::max(maxLength, dp[i]); // Update overall max length
    }

    return maxLength;
}

// Example usage:
// std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
// std::cout << lengthOfLIS(nums) << std::endl; // Output: 4 (e.g., 2, 3, 7, 101)
```

_(Note: There is an O(N log N) solution for LIS using binary search, which is often preferred in competitive programming, but the O(N^2) DP is the more standard DP approach taught first.)_

#### Example 5: 0/1 Knapsack Problem

- **Problem:** Given weights and values of `N` items, put them in a knapsack of capacity `W` to get the maximum total value. You can only take an item or leave it (0/1 choice).
- **Overlapping Subproblems:** To decide whether to include item `i` for capacity `w`, you need the solution for capacity `w` _without_ item `i`, and the solution for capacity `w - weight[i]` _with_ item `i-1`.
- **Optimal Substructure:** The optimal solution for capacity `w` with items 1 to `i` depends on optimal solutions for smaller capacities and subsets of items.
- **State:** `dp[i][w]` represents the maximum value that can be obtained with items `0` to `i-1` (considering first `i` items) and a knapsack capacity of `w`.
- **Base Cases:** `dp[0][w] = 0` for all `w` (0 value with 0 items). `dp[i][0] = 0` for all `i` (0 value with capacity 0).
- **Recurrence Relation:**
  - If `weight[i-1] > w` (current item is too heavy): `dp[i][w] = dp[i-1][w]` (cannot include item `i`, value is same as using items 0 to `i-2` with capacity `w`).
  - If `weight[i-1] <= w`: `dp[i][w] = max(dp[i-1][w], value[i-1] + dp[i-1][w - weight[i-1]])`. This is the maximum of:
    - Not including item `i`: `dp[i-1][w]`
    - Including item `i`: `value[i-1]` + optimal value from items 0 to `i-2` with remaining capacity `w - weight[i-1]`.

**C++ Code (Tabulation - Bottom-Up - O(N\*W)):**

```cpp
#include <vector>
#include <algorithm> // For std::max
#include <iostream>

int knapSack(int W, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    // dp[i][w] = max value using first i items with capacity w
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    // Build dp table in bottom-up manner
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // Base case: 0 items or 0 capacity
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // If current item can be included
            else if (weights[i - 1] <= w) {
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            // If current item cannot be included
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

// Example usage:
// std::vector<int> values = {60, 100, 120};
// std::vector<int> weights = {10, 20, 30};
// int W = 50;
// int n = values.size();
// std::cout << knapSack(W, weights, values, n) << std::endl; // Output: 220 (items 10 and 20)
```

**Space Optimization for Knapsack:**

Notice that `dp[i][w]` only depends on values from the previous row (`dp[i-1]`). We can reduce the space complexity to O(W) by using only two rows or even a single row if we iterate carefully.

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int knapSack_space_optimized(int W, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    // dp[w] will store max value for capacity w using items considered so far
    std::vector<int> dp(W + 1, 0);

    // Iterate through items
    for (int i = 0; i < n; ++i) {
        // Iterate through capacity from W down to weight[i]
        // We iterate backwards to use values from the *previous* item row
        for (int w = W; w >= weights[i]; --w) {
            dp[w] = std::max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }

    return dp[W];
}

// Example usage (same as above):
// std::vector<int> values = {60, 100, 120};
// std::vector<int> weights = {10, 20, 30};
// int W = 50;
// int n = values.size();
// std::cout << knapSack_space_optimized(W, weights, values, n) << std::endl; // Output: 220
```

### 5. Common DP Patterns

- **1D DP:** The state can be represented by a single index, like `dp[i]`. (e.g., Fibonacci, Climbing Stairs, Coin Change)
- **2D DP:** The state requires two indices, like `dp[i][j]`. (e.g., Knapsack, Longest Common Subsequence)
- **DP on Sequences/Arrays:** Problems involving finding optimal substructures within an array or string. (e.g., LIS, Longest Common Subsequence, Maximum Subarray Sum)
- **DP on Grids:** Problems on 2D grids where the state often depends on adjacent cells. (e.g., Unique Paths, Minimum Path Sum)
- **DP on Trees:** More advanced, where the DP state depends on the structure of subtrees.
- **Bitmask DP:** Using bitmasks to represent subsets or states in DP. (More advanced)
- **Digit DP:** Used for problems counting numbers within a range [A, B] that satisfy certain properties. (More advanced)

### 6. Relevant LeetCode Problems

Here's a selection of LeetCode problems covering various DP concepts and difficulties:

**Basic 1D DP:**

- [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
- [322. Coin Change](https://leetcode.com/problems/coin-change/)
- [198. House Robber](https://leetcode.com/problems/house-robber/)
- [213. House Robber II](https://leetcode.com/problems/house-robber-ii/)
- [746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)

**Sequence/Array DP:**

- [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) (Try O(N^2) DP first, then O(N log N))
- [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)
- [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) (Kadane's Algorithm, a form of DP)
- [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) (Classic 2D DP)

**Grid DP:**

- [62. Unique Paths](https://leetcode.com/problems/unique-paths/)
- [63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)
- [64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)

**Knapsack / Unbounded Knapsack:**

- [518. Coin Change II](https://leetcode.com/problems/coin-change-ii/) (Number of ways, unbounded knapsack variant)
- [416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) (Subset Sum, related to Knapsack)

**String DP:**

- [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
- [516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)
- [72. Edit Distance](https://leetcode.com/problems/edit-distance/)
- [115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)

**More Advanced/Specific DP:**

- [10. Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)
- [44. Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)

### 7. Tips for DP Problems in Interviews

1.  **Recognize DP:** Look for recursive structures, problems asking for minimum/maximum values, counts, or boolean feasibility, especially when repeated subproblems are evident.
2.  **Define the State:** This is often the trickiest part. Think about what information you need to carry forward to solve larger subproblems. What parameters change in the recursive calls?
3.  **Write Down the Recurrence:** Express the solution for the current state in terms of solutions to smaller states. Write it down mathematically or in clear pseudocode first.
4.  **Base Cases are Crucial:** Correctly identifying the simplest cases where the answer is trivial is essential.
5.  **Think Recursive (Memoization first):** Sometimes it's easier to formulate the top-down recursive solution with memoization first.
6.  **Then Think Iterative (Tabulation):** Once you have the recurrence and base cases, think about how to fill a DP table iteratively starting from the base cases. Determine the correct loop order.
7.  **Draw the DP Table:** For 2D DP problems, drawing a small DP table and filling it manually for a small example can help you understand the transitions and base cases.
8.  **Consider Space Optimization:** After getting the correct solution, check if the current state's computation only relies on a limited number of previous states. If so, you might be able to optimize space.
9.  **Complexity Analysis:** Determine the time and space complexity. The time complexity is usually the number of states multiplied by the time to compute each state.
10. **Practice!** DP requires practice to develop intuition for defining states and recurrences. Start with simpler 1D problems and gradually move to 2D and other types.

Dynamic Programming can be challenging at first, but with practice, you'll start recognizing the patterns and applying the techniques effectively. Good luck with your interview preparation!
