// Problem statement
// You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

// For example:

// Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
// Note :
// A duplicate number is always present in the given array.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <=  T  <= 10
// 2 <=  N <= 10 ^ 5
// 1 <=  ARR[i]  <= N - 1

// Where 'T' denotes the number of test cases, 'N' denotes the number of elements in the array, and 'ARR[i]' denotes the 'i-th' element of the array 'ARR'.

// Time limit: 1 sec
// Sample Input 1:
// 2
// 5
// 4 2 1 3 1
// 7
// 6 3 1 5 4 3 2
// Sample Output 1:
// 1
// 3
// Explanation of sample input 1:
// For the first test case, 
// The duplicate integer value present in the array is 1. Hence, the answer is 1 in this case.

// For the second test case,
// The duplicate integer value present in the array is 3. Hence, the answer is 3 in this case.
// Sample Input 2:
// 2
// 6 
// 5 1 2 3 4 2  
// 9
// 8 7 2 5 4 7 1 3 6
// Sample Output 2:
// 2
// 7


// Hints:
// 1. Simply calculate the frequency of each value.
// 2. Try to optimise the above approach by using an array to store the frequencies.
// 3. Think of a solution using Floyd’s cycle finding algorithm.
// 4. Try to think of a solution based on bitwise XOR.


int findDuplicate(vector<int> &arr) 
{
    // ✅ Iterate through each element in the array
    for(int i = 0; i < arr.size(); i++) {
        int count = 0; // ✅ Initialize count for current element arr[i]

        // ✅ Compare arr[i] with every other element in the array
        for(int j = 0; j < arr.size(); j++) {
            if(arr[i] == arr[j]) { // ✅ If arr[i] matches arr[j], increase count
                count++;

                // ✅ If the count reaches 2, that means we found the duplicate
                if(count == 2) {
                    return arr[i]; // ✅ Return the first duplicate found
                }
            }
        }
    }

    return 0; // ✅ Return 0 if no duplicate is found (though problem guarantees at least one duplicate)
}

// Time complexity: O(N^2)
// Space complexity: O(1)


// Optimized Approach (Using XOR, O(n) Time)

int findDuplicate(vector<int> &arr) 
{
    // Step 1: Initialize two variables to store XOR results
    int xor1 = 0, xor2 = 0;

    // Step 2: Compute XOR of all elements in the array
    // This will include both unique numbers and the duplicate number
    for(int num : arr){
        xor1 = xor1 ^ num; // XOR each element with xor1
    }

    // Step 3: Compute XOR of numbers from 1 to (n-1)
    // This will create a reference XOR for comparison (without duplicate)
    for(int i = 1; i < arr.size(); i++){
        xor2 = xor2 ^ i; // XOR each number from 1 to (n-1)
    }

    // Step 4: The duplicate number will be xor1 ^ xor2
    // Why? Because all non-duplicate numbers cancel out, leaving only the duplicate
    return xor1 ^ xor2;  
}

// Time complexity: O(N)
// Space complexity: O(1)


// Optimized Approach (Using Hash Map, O(n) Time)

int findDuplicate(vector<int> &arr) 
{
    // Step 1: Create a hash map to store frequency of each element
    unordered_map<int, int> freq;

    // Step 2: Iterate through each element in the array
    for(int num : arr){
        freq[num]++; // Increment frequency of current element
    }

    // Step 3: Find the element with frequency greater than 1
    for(auto it : freq){
        if(it.second > 1){
            return it.first; // Return the duplicate element
        }
    }

    return 0; // Return 0 if no duplicate is found (though problem guarantees at least one duplicate)
}

// Time complexity: O(N)
// Space complexity: O(N)

