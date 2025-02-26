// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.

 

// Example 1:

// Input: n = 27
// Output: true
// Explanation: 27 = 33
// Example 2:

// Input: n = 0
// Output: false
// Explanation: There is no x where 3x = 0.
// Example 3:

// Input: n = -1
// Output: false
// Explanation: There is no x where 3x = (-1).
 

// Constraints:

// -231 <= n <= 231 - 1

// Follow up: Could you solve it without loops/recursion?


//brute force solution

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;

        while(n>1){
            if(n%3!=0) return false;
            n= n/3;
        }
        return true;
        
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)
//explanation of code line by line
// The above code snippet is a solution to the problem that checks if an integer n is a power of three. The function isPowerOfThree takes an integer n as input and returns true if n is a power of three, and false otherwise. The function first checks if n is 0 or negative, in which case it cannot be a power of three and returns false. It then repeatedly divides n by 3 while it is greater than 1, checking if n is divisible by 3 at each step. If n is not divisible by 3, the function returns false, as powers of 3 are completely divisible. If n reaches 1, then n was a power of 3, and the function returns true. The time complexity of the function is O(log(n)), where n is the input integer, and the space complexity is O(1).



class Solution {
public:
    bool isPowerOfThree(int n) {
        // If n is 0 or negative, it cannot be a power of three
        if (n <= 0) return false;
        
        // Loop through all possible powers of 3 up to 3^19 (since 3^20 exceeds int range)
        for (int i = 0; i <= 19; i++) {
            // Calculate 3^i using the pow() function and check if it matches n
            if (pow(3, i) == n) {
                return true; // If a match is found, return true
            }
        }
        
        return false; // If no match is found, return false
    }
};


//bitwise solution
class Solution {
public:
    bool isPowerOfThree(int n) {
        // If n is 0 or negative, it cannot be a power of three
        if (n <= 0) return false;

        // Check if n is a power of three by comparing n & (n-1)
        // If n is a power of three, n & (n-1) will be 0
        return (1162261467 % n == 0);
    }
};

// 1162261467 is the largest power of 3 that fits within the 32-bit integer range
// 3^19 = 1162261467

// Time Complexity: O(1)
// Space Complexity: O(1)
//explanation of code line by line
// The above code snippet is a solution to the problem that checks if an integer n is a power of three. The function isPowerOfThree takes an integer n as input and returns true if n is a power of three, and false otherwise. The function first checks if n is 0 or negative, in which case it cannot be a power of three and returns false. It then checks if 1162261467 (the largest power of 3 that fits within the 32-bit integer range) is divisible by n. If n is a power of three, 1162261467 % n will be 0, and the function returns true. Otherwise, it returns false. The time complexity of the function is O(1), and the space complexity is O(1).

//recursive solution
class Solution {
public:
    bool isPowerOfThree(int n) {
        // Base case: If n is 1, it is a power of three
        if (n == 1) return true;
        
        // Base case: If n is less than 1 or not divisible by 3, it is not a power of three
        if (n < 1 || n % 3 != 0) return false;
        
        // Recursively check if n/3 is a power of three
        return isPowerOfThree(n / 3);
    }
};
