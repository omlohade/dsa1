// Problem statement
// You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

// Note:

// Each pair should be sorted i.e the first value should be less than or equals to the second value. 

// Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= N <= 10^3
// -10^5 <= ARR[i] <= 10^5
// -2 * 10^5 <= S <= 2 * 10^5

// Time Limit: 1 sec
// Sample Input 1:
// 5 5
// 1 2 3 4 5
// Sample Output 1:
// 1 4
// 2 3
// Explaination For Sample Output 1:
// Here, 1 + 4 = 5
//       2 + 3 = 5
// Hence the output will be, (1,4) , (2,3).
// Sample Input 2:
// 5 0
// 2 -3 3 3 -2
// Sample Output 2:
// -3 3
// -3 3
// -2 2

// Approach 1: brute force

#include <bits/stdc++.h>  // Includes all necessary libraries
using namespace std;  // Allows using standard functions without std:: prefix

vector<vector<int>> pairSum(vector<int> &arr, int s) {
    // ✅ Vector of vectors to store all valid pairs
    vector<vector<int>> ans; 

    // ✅ First loop iterates over each element in the array
    for (int i = 0; i < arr.size(); i++) {
        // ✅ Second loop iterates over remaining elements after index i
        for (int j = i + 1; j < arr.size(); j++) {
            // ✅ If the sum of arr[i] and arr[j] equals target s
            if (s == arr[i] + arr[j]) {
                // ✅ Store the pair in sorted order to maintain consistency
                if (arr[i] < arr[j]) {
                    ans.push_back({arr[i], arr[j]}); // Store {smaller, larger}
                } else {
                    ans.push_back({arr[j], arr[i]}); // Store {smaller, larger}
                }
            }
        }
    }

    // ✅ Sorting the final list of pairs for correct output order
    sort(ans.begin(), ans.end());

    return ans; // ✅ Return all valid pairs
}

// Time complexity: O(N^2)
// Space complexity: O(1)


// Approach 2: Using Hash Map

vector<vector<int>> pairSum(vector<int> &arr, int s) {
    // ✅ Vector of vectors to store all valid pairs
    vector<vector<int>> ans; 

    // ✅ Hash Map to store frequency of each element
    unordered_map<int, int> mp; 

    // ✅ Iterate through each element in the array
    for (int i = 0; i < arr.size(); i++) {
        // ✅ Calculate the difference required to get the target sum
        int diff = s - arr[i]; 

        // ✅ If the difference is present in the Hash Map
        if (mp.find(diff) != mp.end()) {
            // ✅ Add the pair to the answer
            ans.push_back({diff, arr[i]}); 
        }

        // ✅ Increment the frequency of the current element
        mp[arr[i]]++; 
    }

    // ✅ Sorting the final list of pairs for correct output order
    sort(ans.begin(), ans.end());

    return ans; // ✅ Return all valid pairs
}