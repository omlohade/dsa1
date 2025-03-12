// 700. Search in a Binary Search Tree
// Easy
// Topics
// Companies
// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

// Example 1:


// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]
// Example 2:


// Input: root = [4,2,7,1,3], val = 5
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [1, 5000].
// 1 <= Node.val <= 107
// root is a binary search tree.
// 1 <= val <= 107


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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if root is NULL, the value doesn't exist
        if (root == nullptr) {
            return nullptr;
        }

        // CASE 1: Current node's value matches val → return this node
        if (root->val == val) {
            return root;  // Found the node! Return it (subtree starts here)
        }

        // CASE 2: If val is less than current node's value → search in left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        }

        // CASE 3: If val is greater than current node's value → search in right subtree
        return searchBST(root->right, val);
    }
};

// Time Complexity: O(H), where H is the height of the tree.
// Space Complexity: O(H), where H is the height of the tree.

// The time complexity is O(H) because we are traversing the tree from the root to the leaf.

// The space complexity is O(H) because the maximum space used by the call stack is the height of the tree.

// The code above is a recursive solution to the problem. We check the current node's value against the target value and decide whether to search in the left or right subtree based on the comparison.

// We return the node if we find it, and return null if we reach a leaf node or if the target value is not found in the tree.





//iterative 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Loop until we reach the end or find the value
        while (root != nullptr) {
            // CASE 1: If we found the node with val
            if (root->val == val) {
                return root;
            }

            // CASE 2: val is smaller → go left
            if (val < root->val) {
                root = root->left;
            }

            // CASE 3: val is greater → go right
            else {
                root = root->right;
            }
        }

        // If we exit the loop, node was not found
        return nullptr;
    }
};



