// Problem statement
// You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

// Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

// Note :
// 1. The length of each array is greater than zero.
// 2. Both the arrays are sorted in non-decreasing order.
// 3. The output should be in the order of elements that occur in the original arrays.
// 4. If there is no intersection present then return an empty array.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 100
// 1 <= N, M <= 10^4
// 0 <= A[i] <= 10^5
// 0 <= B[i] <= 10^5

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 6 4
// 1 2 2 2 3 4
// 2 2 3 3
// 3 2
// 1 2 3
// 3 4  
// Sample Output 1 :
// 2 2 3
// 3   
// Explanation for Sample Input 1 :
// For the first test case, the common elements are 2 2 3 in both the arrays, so we print it.

// For the second test case, only 3 is common so we print 3.
// Sample Input 2 :
// 2
// 3 3 
// 1 4 5
// 3 4 5
// 1 1
// 3
// 6
// Sample Output 2 :
// 4 5
// -1




// Approach 1: Using Two Pointers
// The simplest approach to solve this problem is to use two pointers. We can iterate through both arrays simultaneously and compare the elements. If the elements are the same, we add them to the answer. If the elements are different, we move the pointer of the array with the smaller element. Finally, we return the answer containing all the common elements.

// Algorithm:

// Initialize two pointers i and j to 0.
// Iterate through both arrays simultaneously.
// If the elements at i and j are the same, add them to the answer and increment both pointers.
// If the elements at i and j are different, move the pointer of the array with the smaller element.
// Return the answer containing all the common elements.
// Implementation:

// C++
class Solution {
    vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
    {
        vector<int> ans;
        int i = 0, j = 0;

        // Step 1: Initialize two pointers i and j to 0
        while (i < n && j < m) {
            // Step 2: Compare elements at i and j
            if (arr1[i] == arr2[j]) {
                ans.push_back(arr1[i]);  // Add common element to answer
                i++; j++;  // Move both pointers
            } else if (arr1[i] < arr2[j]) {
                i++;  // Move pointer of array with smaller element
            } else {
                j++;  // Move pointer of array with smaller element
            }
        }

        return ans;  // Return the answer containing all common elements
    }
}; 

// Complexity Analysis
// Time Complexity: O(n + m), where n and m are the sizes of the two arrays.
// Space Complexity: O(1), since we are using only a constant amount of space.
//use when array are sorted

// Approach 2: Using Hash Map

// Another approach to solve this problem is to use a Hash Map. We can iterate through the first array and store the frequency of each number in the Hash Map. Then, we can iterate through the second array and check if the number is present in the Hash Map. If it is present, we add it to the answer. Finally, we return the answer containing all the common elements.

// Algorithm:

// Create a Hash Map to store the frequency of each number in the first array.
// Iterate through the second array and check if the number is present in the Hash Map.
// If the number is present, add it to the answer.
// Return the answer containing all the common elements.

// Implementation:

// C++

class Solution {
    vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
    {
        vector<int> ans;
        unordered_map<int, int> mp;

        // Step 1: Create a Hash Map to store frequency of each element in arr1
        for (int num : arr1) {
            mp[num]++;
        }

        // Step 2: Iterate through arr2 and check if the number is present in the Hash Map
        for (int num : arr2) {
            if (mp.find(num) != mp.end()) {
                ans.push_back(num);  // Add common element to answer
                mp[num]--;  // Decrement frequency in Hash Map
                if (mp[num] == 0) {
                    mp.erase(num);  // Remove element from Hash Map if frequency is 0
                }
            }
        }

        return ans;  // Return the answer containing all common elements
    }
};

// Complexity Analysis
// Time Complexity: O(n + m), where n and m are the sizes of the two arrays.
// Space Complexity: O(n), where n is the size of the first array.
//use when array are not sorted


// Approach 3: brute force


vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    vector <int> ans;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr1[i]==arr2[j]){
                ans.push_back(arr1[i]);
                arr2[j]=-12;
                break;
            }
        }
    }
    return ans;
}


// Complexity Analysis
// Time Complexity: O(n*m), where n and m are the sizes of the two arrays.
// Space Complexity: O(1), since we are using only a constant amount of space.
//use when array are not sorted

