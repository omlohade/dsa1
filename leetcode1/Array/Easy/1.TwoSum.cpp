// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
 

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?


//0(n2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // Start the second loop from the next element (i+1) to avoid using the same index twice
            for (int j = i + 1; j < nums.size(); j++) {
                // Check if the sum of nums[i] and nums[j] equals the target
                if (nums[i] + nums[j] == target) {
                    // If a valid pair is found, return their indices
                    return {i, j};
                }
            }
        }
        // If no such pair is found, return an empty vector
        return {};
    }
};



// 0(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numIndex;  // Key: number, Value: index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];  // The number we need to find

        // Check if complement exists in map
        if (numIndex.find(complement) != numIndex.end()) {
            return {numIndex[complement], i};  // Return indices of pair
        }

        // Store the current number and its index in the map
        numIndex[nums[i]] = i;
    }
    return {};  // Return empty if no pair found
        
    }
};
