// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
 

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109
 

// Follow-up: Could you solve the problem in linear time and in O(1) space?


//approach 1 brute force using 2 for loops
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        // Outer loop to pick each element one by one
        for (int i = 0; i < n; i++) {
            int count = 0;

            // Inner loop to count occurrences of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            // Check if count is greater than n/2
            if (count > n / 2) {
                return nums[i];
            }
        }

        return -1; // Should never reach here as majority element is guaranteed
    }
};

// Time Complexity: O(n^2) - due to nested loops
// Space Complexity: O(1) - no extra space used



// approach 2 using hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Step 1: Create a hash map to count frequency of each element
        unordered_map<int, int> freq;

        int n = nums.size();

        // Step 2: Count occurrences of each element
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++; // increment frequency of nums[i]
        }

        // Step 3: Find the element whose count is > n/2
        for (auto it : freq) {
            if (it.second > n / 2) {
                return it.first;
            }
        }

        return -1; // theoretically won't happen as majority is guaranteed
    }
};

// Time Complexity: O(n) - for counting frequencies
// Space Complexity: O(n) - for storing frequencies in the hash map

//
// approach 3 using Boyer-Moore Voting Algorithm

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

// Time Complexity: O(n) - for counting frequencies
// Space Complexity: O(1) - no extra space used


