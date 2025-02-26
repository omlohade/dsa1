// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1


class Solution {  // Define a class named Solution
public:
    int reverse(int x) {  // Function to reverse an integer x
        long long int rev = 0;  // Use long long int to prevent overflow during calculation

        while (x != 0) {  // Continue looping until all digits are processed
            int n = x % 10;  // Extract the last digit of x
            rev = rev * 10 + n;  // Append the extracted digit to the reversed number
            x = x / 10;  // Remove the last digit from x
        }

        // Check if the reversed number exceeds the 32-bit integer limit
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;  // Return 0 if overflow occurs
        }

        return rev;  // Return the reversed integer
    }
};


// Time Complexity: O(log(x))
// Space Complexity: O(1)
//explanation of code line by line
// The above code snippet is a solution to the problem that reverses the digits of a signed 32-bit integer x. The function reverse takes an integer x as input and returns the reversed integer. The function uses a long long int variable rev to store the reversed integer. It iterates through the digits of x by repeatedly dividing x by 10 and adding the remainder to rev. Finally, it checks if the reversed integer is within the signed 32-bit integer range and returns 0 if it is not. Otherwise, it returns the reversed integer. The time complexity of the function is O(log(x)), where x is the input integer, and the space complexity is O(1).
