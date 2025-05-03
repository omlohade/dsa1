// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
 

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104


// Approach 1: Brute-Force Approach Using Two Nested Loops (O(n^2) Time Complexity)

class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0; // Initialize maximum profit to 0

        // Outer loop to pick each day as the buying day
        for (int i = 0; i < n; i++) {
            // Inner loop to pick each day after the buying day as the selling day
            for (int j = i + 1; j < n; j++) {
                // Calculate profit if bought on day i and sold on day j
                int profit = prices[j] - prices[i];
                // Update maximum profit if this profit is greater
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit; // Return the maximum profit found
    }
};


// Time Complexity: O(n^2) - due to nested loops
// Space Complexity: O(1) - no extra space used

//
// Approach 2: Optimized Approach Using One Loop (O(n) Time Complexity)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Minimum price seen so far
        int maxProfit = 0;       // Maximum profit so far

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;  // Update minimum price
            } else {
                // Calculate profit if sold today
                maxProfit = max(maxProfit, price - minPrice);
            }
        }

        return maxProfit;
    }
};

// Time Complexity: O(n) - where n is the size of the input array prices
// Space Complexity: O(1) - no extra space used

//
// Approach 3: Using Dynamic Programming (O(n) Time Complexity)

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}

// Time Complexity: O(n) - where n is the size of the input array prices
// Space Complexity: O(1) - no extra space used

//it is dp because it is storing the minimum price seen so far and the maximum profit calculated so far in the same loop. 
// dp means remembering the past 
// and using it to calculate the future.

