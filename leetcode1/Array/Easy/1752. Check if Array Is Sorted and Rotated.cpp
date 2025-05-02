// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].
// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 
 

//approach 1 check only for non rotated array

class Solution {
public:
    bool check(vector<int>& nums) {
        for(int i=1 ; i <=nums.size()-1 ; i++){
            if(nums[i]<nums[i-1]){
                return false;
            }  
        }
        return true;   
    }
};

//approach 2 check for rotated array brute force all possible rotations
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(); // Store the size of the input array

        // Try all possible left rotations from 0 to n-1
        for (int k = 0; k < n; ++k) {

            vector<int> rotated; // This will store the rotated version of the array

            // Build the rotated array using left rotation by k positions
            for (int i = 0; i < n; ++i) {
                // (i + k) % n gives the correct index after rotating left by k
                // It wraps around the array when the index goes out of bounds
                rotated.push_back(nums[(i + k) % n]);
            }

            // Now check if the rotated array is sorted in non-decreasing order
            bool isSorted = true; // Assume it is sorted unless we find a problem

            // Loop through the rotated array and compare adjacent elements
            for (int i = 1; i < n; ++i) {
                if (rotated[i] < rotated[i - 1]) {
                    // If current number is smaller than the previous one,
                    // then it is not sorted
                    isSorted = false;
                    break; // No need to check further if already unsorted
                }
            }

            // If this rotation made a sorted array, return true
            if (isSorted) return true;
        }

        // If none of the rotations result in a sorted array, return false
        return false;
    }
};


//approach 3 check for more than 1 drop in the array
public:
    bool check(vector<int>& nums) {
        int n = nums.size();    // Total number of elements in the array
        int count = 0;          // This will count the number of "drop" points (violations of sorted order)

        // Step 1: Count the number of places where the array is NOT in non-decreasing order
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i])
                count++; // This means nums[i-1] > nums[i], i.e., a drop in sorted order
        }

        /*
        Step 2: Special case - check the connection between the last and the first elements
        Why?
        Because if the array is rotated, the drop may also happen between the last and first elements.
        Example:
            [3, 4, 5, 1, 2] -> nums[n-1] = 2, nums[0] = 3 => OK
            [5, 1, 2, 3, 4] -> nums[n-1] = 4, nums[0] = 5 => one drop at the end, expected
            But if nums[n-1] > nums[0], we might have an extra drop not caught in the loop.
        */
        if (nums[n - 1] > nums[0])
            count++; // If there's another drop between last and first, increase count

        // Step 3: If count of such "drop" points is more than 1, it's not a rotated sorted array
        return count <= 1;
    }
};
// Time Complexity: O(n) - We go through the array a constant number of times (at most 2).
// Space Complexity: O(1) - We only use a few extra variables, not dependent on input size.
