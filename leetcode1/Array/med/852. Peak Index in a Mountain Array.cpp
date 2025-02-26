// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1

 

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.


// Approach
// 1. Find the peak element using binary search.

// 2. If the mid element is greater than the next element, then the peak element lies on the left side of the mid element.

// 3. If the mid element is greater than the previous element, then the peak element lies on the right side of the mid element.

// 4. Repeat the process until the peak element is found.

// 5. Return the peak element index.

// 6. Time Complexity: O(log(n))

// 7. Space Complexity: O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int s = 0;                      // Start pointer (left)
        int e = arr.size() - 1;          // End pointer (right)
        int mid = s + (e - s) / 2;       // Compute mid to prevent overflow

        while (s < e) {  // Continue until search space collapses
            if (arr[mid] < arr[mid + 1]) {  
                // If mid is in the increasing part, move right
                s = mid + 1;
            } else {
                // If mid is in the decreasing part, move left
                e = mid;
            }
            mid = s + (e - s) / 2;  // Recalculate mid after moving s/e
        }

        return s; // s (or e) will be at the peak index
    }
};


