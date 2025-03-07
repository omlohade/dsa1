// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

 

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
// Example 2:

// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
// Example 3:

// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

// Constraints:

// 0 <= n <= 30

//recursive approach
class Solution {
public:
    int fib(int n) {
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        // Recursive call
        return fib(n - 1) + fib(n - 2);
    }
};
// Time complexity: O(2^n)
// Space complexity: O(n)



//iterative approach
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        
        int a = 0;
        int b = 1;
        int c;
        
        for(int i=2; i<=n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
};

//memoization approach top down dp

class Solution {
public:
    int fibHelper(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        // If already computed, return stored value
        if (dp[n] != -1) return dp[n];

        // Compute and store the result
        dp[n] = fibHelper(n - 1, dp) + fibHelper(n - 2, dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n + 1, -1);  // Initialize memoization array
        return fibHelper(n, dp);
    }
};

// Time complexity: O(n)
// Space complexity: O(n)

//bottom up dp
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        // Iterative DP approach
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};

// Time complexity: O(n)
// Space complexity: O(n)


