// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1,2]
// Output: [1]
// Example 3:

// Input: nums = [1]
// Output: []
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n
// Each element in nums appears once or twice.




//best using for loop only 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

// Complexity Analysis
// Time Complexity: O(nlogn), where n is the number of elements in the given array.
// Space Complexity: O(1), since we are using only a constant amount of space.

//explanation
// The simplest approach to solve this problem is to sort the given array and then iterate through the array to find all the duplicate numbers. If the current number is the same as the next number, we add it to the answer. Finally, we return the answer containing all the duplicate numbers.

// Algorithm:

// Sort the given array.
// Iterate through the sorted array and find all the duplicate numbers.
// Return all the duplicate numbers found.




// Approach 1: Using Hash Map

// The simplest approach to solve this problem is to use a Hash Map. We can iterate through the given array and store the frequency of each number in the Hash Map. Finally, we can return all the numbers that have a frequency greater than 1.

// Algorithm:

// Create a Hash Map to store the frequency of each number.
// Iterate through the given array and increment the frequency of each number.
// Find all the numbers that have a frequency greater than 1 and return them.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

// Complexity Analysis
// Time Complexity: O(n), where n is the number of elements in the given array.
// Space Complexity: O(n), where n is the number of elements in the given array.




// Approach 2: Using Cyclic Sort
// The given array contains numbers in the range [1, n]. Since all the numbers are unique, the array can be sorted in-place using the Cyclic Sort algorithm. While performing the cyclic sort, if we find a number that is already at its correct position, we skip it. Otherwise, we check if the number at the current index is the same as the number at the index equal to the number itself. If it is not, we swap the numbers. This way, we can find all the duplicate numbers in the array.

// Algorithm:

// Perform the cyclic sort on the given array.
// While performing the cyclic sort, if we find a number that is already at its correct position, we skip it.
// Otherwise, we check if the number at the current index is the same as the number at the index equal to the number itself.
// If it is not, we swap the numbers.
// Finally, we return all the numbers that are not at their correct positions.
// Implementation:

//C++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int i = 0;

        // Step 1: Place each number at its correct position using cyclic sort
        while (i < nums.size()) {
            // If the current number is not in its correct place, swap it
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);  
            } else {
                i++;  // Move to the next index if correctly placed
            }
        }

        // Step 2: Identify duplicates (numbers not in correct places)
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {  // If nums[i] is not at index (i+1), it's a duplicate
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};


// Complexity Analysis  
// Time Complexity: O(n), where n is the number of elements in the given array.
// Space Complexity: O(1), since we are using only a constant amount of space.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;  

        // Step 1: Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;  // Convert number to index

            // Step 2: If the value at the index is already negative, it's a duplicate
            if (nums[index] < 0) {
                ans.push_back(index + 1);  // Store the duplicate number
            }

            // Step 3: Mark the number as visited by making it negative
            nums[index] = -nums[index];
        }

        return ans;
    }
};



// Complexity Analysis
// Time Complexity: O(n), where n is the number of elements in the given array.
// Space Complexity: O(1), since we are using only a constant amount of space.



