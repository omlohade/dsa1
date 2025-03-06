// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

// Constraints:

// 1 <= s.length <= 104
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.
 

// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?


// Approach 1: Using Extra Space

// The simplest approach is to split the string s into words, reverse the order of the words, and then combine them into a single string.

// Algorithm

// Split the string s into words using a built-in split() function. The split() function returns an array of words.
// Reverse the array of words.
// Combine the words into a single string and return it.

// Complexity Analysis

// Time complexity: O(n), where n is the length of the input string s. The split() function takes O(n) time to split the string into words, and the reverse() function takes O(n) time to reverse the array of words.

// Space complexity: O(n), where n is the length of the input string s. We need O(n) extra space to store the array of words.



class Solution {
public:
    string reverseWords(string s) {
        string word;               // To store individual words
        vector<string> words;      // Vector to store all words
        stringstream ss(s);        // Create a stringstream object to process the string

        // Extract words from the string and store them in the vector
        while (ss >> word) {       
            words.push_back(word); // Push each extracted word into the vector
        }

        // Reverse the order of words in the vector
        reverse(words.begin(), words.end());

        string result = "";  // Initialize an empty result string

        // Iterate through the reversed words vector to construct the final string
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }

        return result;  // Return the final reversed sentence
    }
};

// Approach 2: Using Two Pointers

// In this approach, we will reverse the entire string and then reverse each word in the string.

// Algorithm

// Reverse the entire string.
// Reverse each word in the string.
// Remove extra spaces between words.
// Complexity Analysis

// Time complexity: O(n), where n is the length of the input string s. We reverse the entire string in O(n) time and reverse each word in O(n) time.

// Space complexity: O(1). We use only a constant amount of extra space.

class Solution {
public:
    string reverseWords(string s) {
        // Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.length();
        int idx = 0; // Index to keep track of the position of the next character in the result string

        // Iterate through the string
        for (int start = 0; start < n; start++) {
            // Skip spaces
            if (s[start] == ' ') {
                continue;
            }

            // Move the word to the beginning of the string
            if (idx != 0) {
                s[idx++] = ' ';
            }

            // Store the position of the start of the word
            int end = start;

            // Find the end of the word
            while (end < n && s[end] != ' ') {
                s[idx++] = s[end++];
            }

            // Reverse the word
            reverse(s.begin() + idx - (end - start), s.begin() + idx);

            // Move to the next word
            start = end;
        }

        // Resize the string to remove the extra characters
        s.resize(idx);

        return s; // Return the reversed string
    }
};