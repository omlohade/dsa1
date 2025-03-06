// 74. Search a 2D Matrix
// Medium
// Topics
// Companies
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns
        
        int left = 0, right = m * n - 1; // Binary search in 1D space

        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoid integer overflow

            int row = mid / n;  // Finding row index
            int col = mid % n;  // Finding column index
            
            if (matrix[row][col] == target) {
                return true; // Target found
            } 
            else if (matrix[row][col] < target) {
                left = mid + 1; // Search in right half
            } 
            else {
                right = mid - 1; // Search in left half
            }
        }
        
        return false; // Target not found
    }
};

// Driver code to test
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    
    if (sol.searchMatrix(matrix, target)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}
// Complexity Analysis

// The time complexity for this approach is O(log(m * n)) since we are performing binary search in a 1D space of size m * n.

// The space complexity is O(1) since we are not using any extra space.



