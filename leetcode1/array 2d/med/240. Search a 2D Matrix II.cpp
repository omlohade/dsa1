// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
 

// Example 1:


// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true
// Example 2:


// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= n, m <= 300
// -109 <= matrix[i][j] <= 109
// All the integers in each row are sorted in ascending order.
// All the integers in each column are sorted in ascending order.
// -109 <= target <= 109



#include <iostream>
#include <vector>
using namespace std;

//greedy approach
//start from the top right corner   
//if the target is greater than the current element, move down
//if the target is smaller than the current element, move left
//if the target is equal to the current element, return true
//if the target is not found, return false




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns

        int row = 0;      // Start from the top row
        int col = n - 1;  // Start from the last column

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;  // Found the target
            } 
            else if (matrix[row][col] > target) {
                col--;  // Move left if the value is greater
            } 
            else {
                row++;  // Move down if the value is smaller
            }
        }
        
        return false; // Target not found
    }
};

// time complexity: O(m + n)
// space complexity: O(1)


// 📌 Algorithm for Binary Search Approach
// Iterate through each row in the matrix.
// Apply Binary Search in each row.
// If the element is found, return true.
// If we finish searching all rows and do not find the target, return false.


class Solution {
public:
    bool binarySearch(vector<int>& row, int target) {
        int left = 0, right = row.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (row[mid] == target) return true;
            else if (row[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix) {
            if (binarySearch(row, target)) return true;
        }
        return false;
    }
};
