// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.
 

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Iterate through the entire array
        for(int i = 0; i < nums.size(); i++) {
            // Compare each element with the next elements
            for(int j = i + 1; j < nums.size(); j++) {
                // If the current element is greater than the next one, swap them
                if(nums[i] > nums[j]) {
                    int temp = nums[i];  // Temporary variable to hold nums[i]
                    nums[i] = nums[j];   // Swap nums[i] with nums[j]
                    nums[j] = temp;      // Assign temp value to nums[j]
                }
            }
        }   
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(1)

//explaination
// The above code snippet is a brute force solution to the problem. The function sortColors takes a vector of integers nums as input and sorts the elements in the array in-place. The function uses two nested loops to compare each element with the next elements in the array and swaps them if the current element is greater than the next one. This process continues until the entire array is sorted.

//counting sort two pass 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Step 1: Count the occurrences of each color (0, 1, and 2)
        int count[3] = {0};  // Array to store counts of 0s, 1s, and 2s
        
        // Iterate through the input array and count each color
        for (int num : nums) {
            count[num]++;  // Increment the count at the index corresponding to the color
        }
        
        // Step 2: Overwrite the original array with the sorted colors
        int index = 0;  // Index to track the position for inserting values
        
        // Iterate over the three possible colors (0, 1, and 2)
        for (int i = 0; i < 3; i++) { 
            // Place the color `i` into the `nums` array `count[i]` times
            for (int j = 0; j < count[i]; j++) {
                nums[index++] = i;  // Assign color `i` to the correct position
            }
        }
    }
};



// Time Complexity: O(n)
// Space Complexity: O(1)

// Dutch National Flag Algorithm (One-Pass Solution)
// The Dutch National Flag algorithm is a one-pass solution to sort an array of 0s, 1s, and 2s. The algorithm uses three pointers to partition the array into three sections: the 0s, the 1s, and the 2s. The algorithm iterates through the array and swaps elements to maintain the invariant that all elements to the left of the low pointer are 0s, all elements to the right of the high pointer are 2s, and all elements between the low and high pointers are 1s.


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;          // Pointer to track the position of 0s
        int high = nums.size() - 1;  // Pointer to track the position of 2s
        
        // Iterate through the array
        for (int i = 0; i <= high; i++) {
            // If the current element is 0, swap it with the element at the low pointer
            if (nums[i] == 0) {
                swap(nums[i], nums[low]);
                low++;  // Increment the low pointer
            }
            // If the current element is 2, swap it with the element at the high pointer
            else if (nums[i] == 2) {
                swap(nums[i], nums[high]);
                high--;  // Decrement the high pointer
                i--;     // Recheck the current element after swapping
            }
        }
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)


