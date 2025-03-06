
// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        if (matrix.empty()) return result; // Edge case: empty matrix

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // 1️⃣ Move from left to right across the top row
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++; // Move top boundary down

            // 2️⃣ Move from top to bottom along the right column
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move right boundary left

            // 3️⃣ Move from right to left across the bottom row (only if rows remain)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--; // Move bottom boundary up
            }

            // 4️⃣ Move from bottom to top along the left column (only if columns remain)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move left boundary right
            }
        }

        return result;
    }
};

// Driver code to test
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    vector<int> result = sol.spiralOrder(matrix);
    
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
