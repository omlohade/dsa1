// The frequency of an element is the number of times it occurs in an array.

// You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

// Return the maximum possible frequency of an element after performing at most k operations.

 

// Example 1:

// Input: nums = [1,2,4], k = 5
// Output: 3
// Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
// 4 has a frequency of 3.
// Example 2:

// Input: nums = [1,4,8,13], k = 5
// Output: 2
// Explanation: There are multiple optimal solutions:
// - Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
// - Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
// - Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
// Example 3:

// Input: nums = [3,9,6], k = 2
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
// 1 <= k <= 105


//brute force 
//O(n^2)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int maxFreq = 1; // Minimum frequency is 1 (the element itself)

        // Step 2: Iterate through the array from the end
        // We choose nums[i] as the target value we want to match
        for (int i = nums.size() - 1; i >= 0; i--) {
            long long remainingK = k; // Reset k for each target element
            int freq = 1;             // Frequency starts from 1 (itself)

            // Step 3: Iterate backward from i-1 to 0
            for (int j = i - 1; j >= 0; j--) {
                // Calculate the increment needed to make nums[j] == nums[i]
                long long incrementNeeded = (long long)nums[i] - nums[j];

                // Check if we have enough k to make this change
                if (remainingK >= incrementNeeded) {
                    remainingK -= incrementNeeded; // Use k for this increment
                    freq++;                        // Increase frequency count
                } else {
                    // Not enough k left, break out of the loop
                    break;
                }
            }

            // Step 4: Update the maximum frequency found so far
            maxFreq = max(maxFreq, freq);
        }

        // Step 5: Return the largest frequency
        return maxFreq;
    }
};



//O(nlogn)

// Approach 2: Sliding Window

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Step 1: Sort the array in ascending order
        // We want to make smaller numbers equal to bigger numbers.
        sort(nums.begin(), nums.end());

        long long total = 0; // Total sum of numbers inside the current window
        int left = 0;        // Left pointer of the window
        int maxFreq = 0;     // Variable to keep track of maximum frequency we can achieve

        // Step 2: Start moving the right pointer through the array
        for (int right = 0; right < nums.size(); right++) {
            total += nums[right]; // Add the current number to the total sum of the window

            // Step 3: Check if the cost to make all numbers in the window equal to nums[right] is > k
            // The cost formula is: nums[right] * window_size - total
            while ((long long)nums[right] * (right - left + 1) - total > k) {
                // If cost is too big, shrink the window from the left side
                total -= nums[left]; // Remove nums[left] from total
                left++;              // Move left pointer to the right
            }

            // Step 4: Update the maximum frequency if current window is larger
            maxFreq = max(maxFreq, right - left + 1);
        }

        // Step 5: Return the largest frequency found
        return maxFreq;
    }
};

// Time Complexity: O(nlogn) for sorting + O(n) for the sliding window = O(nlogn)
// Space Complexity: O(1) since we are using a constant amount of space

