// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
// Example 2:

// Input: arr = [1,2]
// Output: false
// Example 3:

// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
// Output: true
 

// Constraints:

// 1 <= arr.length <= 1000
// -1000 <= arr[i] <= 1000




class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;  // ✅ Step 1: Create a hashmap to store frequency counts
        unordered_set<int> st;      // ✅ Step 2: Create a hash set to track unique occurrence values

        // ✅ Step 3: Count occurrences of each element
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;  // Increase frequency of element `arr[i]`
        }

        // ✅ Step 4: Check if occurrences are unique
        for(auto it : mp){
            /*
                `it.first` -> The key (element from `arr`)
                `it.second` -> The value (count of occurrences of the element)
            */

            if(st.find(it.second) != st.end()) 
                return false; // If count is already present, return false (not unique)

            st.insert(it.second);  // Insert the count into the set
        }

        return true;  // ✅ If all counts are unique, return true
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n)

//explanation of code line by line

// The above code snippet is a solution to the problem that checks if the number of occurrences of each value in an array is unique. The function uniqueOccurrences takes a vector of integers arr as input and returns true if the number of occurrences of each value in the array is unique, and false otherwise. The function uses two data structures, an unordered_map mp to store the count of occurrences of each value in the array, and an unordered_set st to store the unique counts. It iterates through the array and populates the map mp with the count of occurrences of each value. It then iterates through the map and checks if the count of occurrences is already present in the set st. If it is, the function returns false, as the count is not unique. If the count is unique, it is added to the set st. If the loop completes without finding any duplicate counts, the function returns true. The time complexity of the function is O(n), where n is the size of the input array, and the space complexity is also O(n) due to the use of the map and set.

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;  // ✅ Step 1: Create a hashmap to count frequency of elements

        // ✅ Step 2: Count occurrences of each element in `arr`
        for (int num : arr) {  
            freq[num]++;  // Increments the count of `num` in the hashmap
        }

        unordered_set<int> occurrences;  // ✅ Step 3: Create a set to store unique frequencies

        // ✅ Step 4: Iterate through the hashmap and check for duplicate frequencies
        for (auto it : freq) {  
            /*
                `it.first` represents the key (element from `arr`)
                `it.second` represents the value (count of occurrences of the element)
            */

            if (!occurrences.insert(it.second).second) {
                // `insert(it.second)` tries to insert the occurrence count into the set.
                // If the insertion fails (i.e., `it.second` was already present), return `false`
                return false; 
            }
        }

        return true;  // ✅ If all occurrences are unique, return `true`
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

//explanation of code line by line

// The above code snippet is a solution to the problem that checks if the number of occurrences of each value in an array is unique. The function uniqueOccurrences takes a vector of integers arr as input and returns true if the number of occurrences of each value in the array is unique, and false otherwise. The function uses two data structures, an unordered_map freq to store the count of occurrences of each value in the array, and an unordered_set occurrences to store the unique counts. It iterates through the array and populates the map freq with the count of occurrences of each value. It then iterates through the map and checks if the count of occurrences is already present in the set occurrences. If it is, the function returns false, as the count is not unique. If the count is unique, it is added to the set occurrences. If the loop completes without finding any duplicate counts, the function returns true. The time complexity of the function is O(n), where n is the size of the input array, and the space complexity is also O(n) due to the use of the map and set.

// ✅ Step 1: Create a hashmap to store frequency counts
// ✅ Step 2: Create a hash set to track unique occurrence values
// ✅ Step 3: Count occurrences of each element
// ✅ Step 4: Check if occurrences are unique


