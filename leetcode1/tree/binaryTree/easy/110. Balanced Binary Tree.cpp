// 110. Balanced Binary Tree
// Easy
// Topics
// Companies
// Given a binary tree, determine if it is height-balanced.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // Helper function to check height and balance simultaneously
    int checkHeight(TreeNode* root) {
        // Base case: Empty tree has height 0 and is balanced
        if (root == nullptr)
            return 0;

        // Recursively check the height of left subtree
        int leftHeight = checkHeight(root->left);
        // If left subtree is unbalanced, return -1 immediately
        if (leftHeight == -1)
            return -1;

        // Recursively check the height of right subtree
        int rightHeight = checkHeight(root->right);
        // If right subtree is unbalanced, return -1 immediately
        if (rightHeight == -1)
            return -1;

        // If difference between left and right subtree heights is more than 1 => Not balanced
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return the height of this subtree (1 + max of left and right heights)
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        // If the checkHeight returns -1, it means it's not balanced
        return checkHeight(root) != -1;
    }
};



