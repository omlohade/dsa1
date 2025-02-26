// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

 

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: n = 3
// Output: false
 

// Constraints:

// -231 <= n <= 231 - 1



class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Loop through all possible powers of 2 up to 2^30 (since 2^31 exceeds int range)
        for(int i = 0; i <= 30; i++) {
            // Calculate 2^i using the pow() function and check if it matches n
            if(pow(2, i) == n) {
                return true; // If a match is found, return true
            }
        }
        return false; // If no match is found, return false
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)
//explanation of code line by line  
// The above code snippet is a solution to the problem that checks if an integer n is a power of two. The function isPowerOfTwo takes an integer n as input and returns true if n is a power of two, and false otherwise. The function iterates through all possible powers of 2 up to 2^30 (since 2^31 exceeds the int range) and calculates 2^i using the pow() function. It then checks if the calculated value matches n and returns true if a match is found. If no match is found, the function returns false. The time complexity of the function is O(log(n)), where n is the input integer, and the space complexity is O(1).


class Solution {
public:
    bool isPowerOfTwo(int n) {
        // If n is 0 or negative, it cannot be a power of two
        if (n <= 0) return false;

        // Keep dividing n by 2 while it is greater than 1
        while (n > 1) {
            // If n is not divisible by 2, return false (since powers of 2 are completely divisible)
            if (n % 2 != 0) return false;
            
            // Divide n by 2 to check the next power
            n = n / 2;
        }

        // If we reach 1, then n was a power of 2
        return true;
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)
//explanation of code line by line
// The above code snippet is a solution to the problem that checks if an integer n is a power of two. The function isPowerOfTwo takes an integer n as input and returns true if n is a power of two, and false otherwise. The function first checks if n is 0 or negative, in which case it cannot be a power of two and returns false. It then repeatedly divides n by 2 while it is greater than 1, checking if n is divisible by 2 at each step. If n is not divisible by 2, the function returns false, as powers of 2 are completely divisible. If n reaches 1, then n was a power of 2, and the function returns true. The time complexity of the function is O(log(n)), where n is the input integer, and the space complexity is O(1).


//recursive solution
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Base case: If n is 1, it is a power of two
        if (n == 1) return true;
        
        // Base case: If n is less than 1 or not divisible by 2, it is not a power of two
        if (n < 1 || n % 2 != 0) return false;
        
        // Recursively check if n/2 is a power of two
        return isPowerOfTwo(n / 2);
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(log(n))
//explanation of code line by line
// The above code snippet is a solution to the problem that checks if an integer n is a power of two using recursion. The function isPowerOfTwo takes an integer n as input and returns true if n is a power of two, and false otherwise. The function uses recursion to check if n is a power of two by dividing n by 2 at each step. The base cases are defined as follows: if n is 1, it is a power of two and the function returns true; if n is less than 1 or not divisible by 2, it is not a power of two and the function returns false. The time complexity of the function is O(log(n)), where n is the input integer, and the space complexity is O(log(n)) due to the recursive calls.


//bitwise solution
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // If n is 0 or negative, it cannot be a power of two
        if (n <= 0) return false;

        // Check if n is a power of two by comparing n & (n-1)
        // If n is a power of two, n & (n-1) will be 0
        return (n & (n - 1)) == 0;
    }
};

// n = 8  ->  1000
// n-1 = 7 ->  0111
// ----------------
// 8 & 7  ->  0000 ✅ Power of 2

// n = 10  ->  1010
// n-1 = 9  ->  1001
// ----------------
// 10 & 9  ->  1000 ❌ Not power of 2


// Time Complexity: O(1)
// Space Complexity: O(1)
//explanation of code line by line
// The above code snippet is a solution to the problem that checks if an integer n is a power of two using bitwise operations. The function isPowerOfTwo takes an integer n as input and returns true if n is a power of two, and false otherwise. The function first checks if n is 0 or negative, in which case it cannot be a power of two and returns false. It then checks if n is a power of two by comparing n & (n-1). If n is a power of two, n & (n-1) will be 0, and the function returns true. The time complexity of the function is O(1), and the space complexity is O(1).


