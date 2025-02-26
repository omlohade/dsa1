// Problem statement
// You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.

// An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

// Note:
// 1. You can return the list of values in any order. For example, if a valid triplet is {1, 2, -3}, then {2, -3, 1}, {-3, 2, 1} etc is also valid triplet. Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
// 2. The elements in the array need not be distinct.
// 3. If no such triplet is present in the array, then return an empty list, and the output printed for such a test case will be "-1".
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <=  50
// 1 <= N <= 10^3  
// -10^6 <= ARR[i] <= 10^6
// -10^9 <= K <= 10^9

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 5
// 10 5 5 5 2
// 12
// Sample Output 1:
// 5 5 2
// Explanation for Sample Input 1:
// 5 5 2 is the only triplet that adds up to 12. Note that the order of the output doesn’t matter, so 5 2 5 or 2 5 5 is also acceptable.
// Sample Input 2:
// 3
// 6
// 1 2 3 1 2 3
// 6
// 4
// 1 2 3 4 
// 11
// 6
// 1 1 2 2 1 1
// 4
// Sample Output 2:
// 1 2 3
// -1
// 1 1 2
// Explanation for Sample Input 2:
// In the first input, (1, 2, 3) is the only unique triplet that adds up to six.

// In the second input, since there are no such triplets, we print -1.

// For the third input, the only distinct triplet is (1, 1, 2), so just print 1 1 2.



// Approach 1: brute force

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    // ? Vector to store unique triplets
    vector<vector<int>> unique;
    
    // ? Sorting the array to avoid duplicate triplets
    sort(arr.begin(), arr.end());

    // ? Using three nested loops to find triplets
    for(int i = 0; i < n - 2; i++) {  // First element
        for(int j = i + 1; j < n - 1; j++) {  // Second element
            for(int k = j + 1; k < n; k++) {  // Third element
                if(arr[i] + arr[j] + arr[k] == K) {
                    unique.push_back({arr[i], arr[j], arr[k]}); // ? Add valid triplet
                }
            }
        }
    }

    // ? Remove duplicate triplets using `set`
    set<vector<int>> s(unique.begin(), unique.end());
    unique.assign(s.begin(), s.end());

    return unique; // ? Return the vector of unique triplets
}

// Time complexity: O(N^3)
// Space complexity: O(1)

// Approach 2: Using Hash Map

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n; ++i) {
        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i-1]) 
            continue;
        
        int target = K - arr[i];
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            
            if (sum == target) {
                res.push_back({arr[i], arr[left], arr[right]});
                
                // Skip duplicates for left and right
                while (left < right && arr[left] == arr[left+1]) left++;
                while (left < right && arr[right] == arr[right-1]) right--;
                
                left++;
                right--;
            } 
            else if (sum < target) left++;
            else right--;
        }
    }
    
    return res;
}

// Time complexity: O(N^2)
// Space complexity: O(1)

