// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0; // Start pointer (beginning of string)
        int e = s.length() - 1; // End pointer (last character of string)

        // Loop until both pointers meet or cross
        while (st <= e) {

            // If the character at 'st' is not alphanumeric, move to the next character
            if (!isalnum(s[st])) {
                st++;
            } 
            // If the character at 'e' is not alphanumeric, move to the previous character
            else if (!isalnum(s[e])) {
                e--;
            } 
            else {
                // Convert both characters to lowercase and compare
                if (tolower(s[st]) != tolower(s[e])) {
                    return false;  // If characters don't match, it's not a palindrome
                }
                // Move both pointers inward for the next comparison
                st++;
                e--;
            }
        }
        return true; // If loop completes, the string is a palindrome
    }
};