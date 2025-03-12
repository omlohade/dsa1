// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

// Example 2:

// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]
// Explanation: The tree does not contain a node with value = 0.
// Example 3:

// Input: root = [], key = 0
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -105 <= Node.val <= 105
// Each node has a unique value.
// root is a valid binary search tree.
// -105 <= key <= 105


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

private:
    // Function to find minimum value node in a subtree
    TreeNode* minVal(TreeNode* root){
        TreeNode* temp = root;
        // Keep moving left to find the smallest value
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: if root is null
        if(root == NULL){
            return NULL;
        }

        // If key is found at root
        if(root->val == key){
            
            // CASE 1: Leaf node
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            // CASE 2: Only right child exists
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // CASE 3: Only left child exists
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // CASE 4: Two children
            if(root->left != NULL && root->right != NULL){
                // Find min value from right subtree (successor)
                int mini = minVal(root->right)->val;
                // Replace root's val with min value
                root->val = mini;
                // Delete that node in right subtree
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }
        else if(root->val > key){
            // Key lies in left subtree
            root->left = deleteNode(root->left, key);
            return root;
        }
        else{
            // Key lies in right subtree
            root->right = deleteNode(root->right, key);
            return root;
        }

        return root; // Redundant in this code, but safe
    }
};


// Time Complexity: O(H), where H is the height of the tree.
// Space Complexity: O(H), where H is the height of the tree.
// The time complexity is O(H) because we are traversing the tree from the root to the leaf.
// The space complexity is O(H) because we are using a recursive approach to traverse the tree. The maximum depth of the recursion tree is H.

// The above solution is a recursive approach to delete a node from a BST. We have three cases to consider:

// If the node to be deleted is a leaf node, we simply delete it.
// If the node to be deleted has only one child, we replace the node with its child.
// If the node to be deleted has two children, we find the inorder successor of the node, replace the node's value with the inorder successor's value, and delete the inorder successor.
// We recursively call the deleteNode function on the left or right subtree based on the value of the node to be deleted. We return the root of the subtree after deleting the node.

