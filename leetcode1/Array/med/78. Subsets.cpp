// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

//recursive approach
//start from the first element
//for each element, we have two choices: include or exclude
//if we include the element, add it to the output and move to the next element
//if we exclude the element, move to the next element
//base case: if the index is greater than or equal to the size of the array, add the output to the answer
//return the answer



class Solution {

private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> & ans){
        //base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude
        solve(nums,output,index+1,ans);

        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);


    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index =0;

        solve(nums,output,index,ans);
        return ans;
        
    }
};

// Time complexity: O(2^n)
// Space complexity: O(n)

//bit manipulation approach

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total_subsets = 1 << n;  // Total subsets = 2^n
        vector<vector<int>> result;

        // Iterate over all possible subsets
        for (int mask = 0; mask < total_subsets; mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                // Check if the i-th bit is set in mask
                if (mask & (1 << i)) {  
                    subset.push_back(nums[i]);  // Include nums[i] in the subset
                }
            }
            result.push_back(subset);  // Store the subset
        }

        return result;
    }
};

/*
🔍 Explanation:
- We iterate over `2^n` subset possibilities (from `0` to `2^n - 1`).
- Each number's binary representation determines which elements are included in the subset.
  - Example for nums = [1,2,3]:
    - `000` -> []
    - `001` -> [3]
    - `010` -> [2]
    - `011` -> [2,3]
    - `100` -> [1]
    - `101` -> [1,3]
    - `110` -> [1,2]
    - `111` -> [1,2,3]
*/

/*
🕒 Time Complexity: O(n * 2^n) → We generate `2^n` subsets, and each subset takes O(n) to construct.
📌 Space Complexity: O(2^n) → Stores all subsets.
✅ Best for small n (≤ 10), avoids recursion overhead.
*/


//iterative approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = { { } };  // Start with an empty subset

        // Iterate over each number in nums
        for (int num : nums) {
            int size = result.size();  // Get current number of subsets
            for (int i = 0; i < size; i++) {
                vector<int> newSubset = result[i];  // Copy existing subset
                newSubset.push_back(num);  // Add the new element
                result.push_back(newSubset);  // Store new subset
            }
        }

        return result;
    }
};

/*
🔍 Explanation:
- Start with `result = [[]]` (empty subset).
- For each number in `nums`, create new subsets by adding it to all existing subsets.
  - Example for nums = [1,2,3]:
    - Start: `[[]]`
    - Add `1`: `[[], [1]]`
    - Add `2`: `[[], [1], [2], [1,2]]`
    - Add `3`: `[[], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]]`
*/

/*
🕒 Time Complexity: O(n * 2^n) → Each number doubles the number of subsets.
📌 Space Complexity: O(2^n) → Stores all subsets.
✅ No recursion, easy to understand.
*/


//backtracking approach
class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // Store the current subset
        result.push_back(current);

        // Explore further subsets by adding each remaining element
        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);  // Include nums[i] in the subset
            backtrack(nums, i + 1, current, result);  // Recursively explore next elements
            current.pop_back();  // Remove last element to backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};

/*
🔍 Explanation:
- Start with an empty subset.
- At each step:
  - Add the current subset to `result`.
  - Include the next element and recursively explore further subsets.
  - Remove the last element (backtrack) to try other combinations.
  - Example for nums = [1,2,3]:
    - Start: `[]`
    - Add `1`: `[1]`
    - Add `2`: `[1,2]`
    - Add `3`: `[1,2,3]`, backtrack to `[1,2]`
    - Remove `2`, add `3`: `[1,3]`, backtrack to `[1]`
    - Remove `1`, add `2`: `[2]`, add `3`: `[2,3]`, backtrack to `[2]`
    - Remove `2`, add `3`: `[3]`
*/

/*
🕒 Time Complexity: O(n * 2^n) → Generates `2^n` subsets, each takes O(n).
📌 Space Complexity: O(n) → Only stores the call stack.
✅ Efficient recursion, avoids redundant calls.
*/

