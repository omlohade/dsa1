// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).

 

// Example 1:

// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
// Example 2:

// Input: matrix = [[-5]], k = 1
// Output: -5
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 300
// -109 <= matrix[i][j] <= 109
// All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
// 1 <= k <= n2
 

// Follow up:

// Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
// Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.

#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // Min-heap to store (value, row index, column index)
        priority_queue< pair<int, pair<int, int>>, 
                        vector< pair<int, pair<int, int>> >, 
                        greater< pair<int, pair<int, int>>> > minHeap;

        // Step 1: Push the first element of each row into the min-heap
        for(int i = 0; i < n; i++) {
            int value = matrix[i][0];
            // (value, (row, column))
            minHeap.push({value, {i, 0}});
        }

        // Step 2: Extract min k times
        int count = 0;
        int result = 0;

        while(count < k) {
            auto current = minHeap.top();
            minHeap.pop();

            result = current.first;  // The smallest element in the heap
            int row = current.second.first;
            int col = current.second.second;

            // Push the next element in the same row into the heap
            if(col + 1 < n) {
                int nextVal = matrix[row][col + 1];
                minHeap.push({nextVal, {row, col + 1}});
            }

            count++;
        }

        return result;
    }
};

// Time complexity: O(klogn)
// Space complexity: O(n)

// The time complexity is O(klogn) because we are extracting the minimum element from the heap k times. Each extraction takes O(logn) time.

// The space complexity is O(n) because we are storing at most n elements in the heap.

// The above solution uses a min-heap to store the smallest element from each row. We first push the first element of each row into the heap. Then, we extract the minimum element from the heap k times. For each extracted element, we push the next element in the same row into the heap. This way, we can find the kth smallest element in the matrix.



class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        // Define the search range: min and max values in the matrix
        int low = matrix[0][0];                      // smallest element
        int high = matrix[n-1][n-1];                 // largest element

        int ans = low;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            // Count how many elements are <= mid
            int count = countLessEqual(matrix, mid);
            
            if(count < k) {
                // Move right → we need more elements
                low = mid + 1;
            } else {
                // Potential answer found → move left to find smaller candidates
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }

private:
    // Helper function to count elements <= target in the matrix
    int countLessEqual(const vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int count = 0;
        
        // Start from bottom-left corner
        int row = n - 1;
        int col = 0;
        
        while(row >= 0 && col < n) {
            if(matrix[row][col] <= target) {
                // All elements above this in the column are also <= target
                count += (row + 1);
                col++;
            } else {
                // Move up → elements are too big
                row--;
            }
        }

        return count;
    }
};

// Time complexity: O(nlog(max-min))
// Space complexity: O(1)

// The time complexity is O(nlog(max-min)), where n is the number of rows in the matrix and max and min are the maximum and minimum values in the matrix, respectively. The binary search runs in O(log(max-min)) time, and we perform the binary search k times.

// The space complexity is O(1) since we are not using any extra space.

// The above solution uses binary search to find the kth smallest element in the matrix. We first define the search range as the minimum and maximum values in the matrix. Then, we perform binary search on this range to find the kth smallest element. For each mid value, we count how many elements in the matrix are less than or equal to mid. If the count is less than k, we move right; otherwise, we move left. This way, we can find the kth smallest element in the matrix.

// The countLessEqual function is used to count the number of elements in the matrix that are less than or equal to the target value. We start from the bottom-left corner of the matrix and move up or right based on the comparison of the current element with the target value. This way, we can count the number of elements that are less than or equal to the target value in the matrix.

// The above solution is more efficient than the heap-based solution since it uses binary search to find the kth smallest element in the matrix. The time complexity of the binary search solution is O(nlog(max-min)), which is better than the heap-based solution's time complexity of O(klogn).

// The binary search solution has a time complexity of O(nlog(max-min)) and a space complexity of O(1). It is more efficient than the heap-based solution, which has a time complexity of O(klogn) and a space complexity of O(n).

