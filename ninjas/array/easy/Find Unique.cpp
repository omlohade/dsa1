// Problem statement
// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

// You need to find and return that number which is unique in the array/list.

//  Note:
// Unique element is always present in the array/list according to the given condition.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 2 3 1 6 3 6 2
// Sample Output 1:
// 1
// Explanation: The array is [2, 3, 1, 6, 3, 6, 2]. Here, the numbers 2, 3, and 6 are present twice, and the number 1 is present only once. So, the unique number in this array is 1.
// Sample Input 2:
// 2
// 5
// 2 4 7 2 7
// 9
// 1 3 1 3 6 6 7 10 7
// Sample Output 2:
// 4
// Explanation: In the first test case, the array is [2, 4, 7, 2, 7]. Here, the numbers 2 and 7 are present twice, and the number 4 is present only once. So, the unique number in this array is 4.

// 10
// Explanation: In the second test case, the array is [1, 3, 1, 3, 6, 6, 7, 10, 7]. Here, the numbers 1, 3, 6, and 7 are present twice, and the number 10 is present only once. So, the unique number in this array is 10.

int findUnique(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int count = 0;
        
        // Count occurrences of arr[i]
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        // If count is 1, return the unique element
        if (count == 1) {
            return arr[i];
        }
    }
    
    return -1; // Return -1 if no unique element found
}

//brute force approach
// Time complexity: O(N^2)
// Space complexity: O(1)

// Optimized Approach (Using XOR, O(n) Time)
int findUnique(int *arr, int size) {
    // Write your code here
    int ans = 0;
    for(int i = 0; i < size; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

// Time complexity: O(N)
// Space complexity: O(1)


// Optimized Approach (Using Hash Map, O(n) Time)
#include <unordered_map>

int findUnique(int *arr, int size) {
    unordered_map<int, int> freqMap;

    // Count occurrences of each element
    for (int i = 0; i < size; i++) {
        freqMap[arr[i]]++;
    }

    // Find the first unique element
    for (int i = 0; i < size; i++) {
        if (freqMap[arr[i]] == 1) {
            return arr[i]; // Return the first element that appears only once
        }
    }

    return -1; // Return -1 if no unique element is found
}