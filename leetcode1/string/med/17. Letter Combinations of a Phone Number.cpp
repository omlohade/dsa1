// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].


class Solution {
public:
    // Mapping of digits to letters as per phone keypad
    vector<string> digitToLetters = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int index, string& current, vector<string>& result) {
        // Base Case: If we have processed all digits, store the combination
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters corresponding to the current digit
        string letters = digitToLetters[digits[index] - '0']; // Convert char to int
        
        // Iterate through each possible letter and explore further
        for (char letter : letters) {
            current.push_back(letter);      // Choose letter
            backtrack(digits, index + 1, current, result); // Recur with next digit
            current.pop_back();             // Undo choice (Backtracking step)
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Edge case: Empty input
        
        vector<string> result;
        string current;
        backtrack(digits, 0, current, result);
        return result;
    }
};

/*
🔍 Explanation:
1. **Base case:** If index == digits.size(), store the combination in `result`.
2. **Recursive step:** Process the current digit:
   - Get corresponding letters.
   - Try each letter, recursively moving to the next digit.
   - Undo the choice before moving to the next option (Backtracking).
   
📌 Backtracking is necessary to **avoid storing unnecessary paths** and ensure all combinations are explored efficiently.
*/

/*
🕒 Time Complexity: O(4ⁿ) → Each digit has max 4 letters (like '7' → "pqrs"), so worst case is O(4ⁿ).
📌 Space Complexity: O(n) → Call stack depth is n (length of digits).
✅ Efficient and elegant recursive approach.
*/
