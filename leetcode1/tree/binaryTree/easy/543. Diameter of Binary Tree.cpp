// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

 

// Example 1:


// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
// Example 2:

// Input: root = [1,2]
// Output: 1
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -100 <= Node.val <= 100


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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left,right)+1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int opt1 =  diameterOfBinaryTree(root->left);
        int opt2 =  diameterOfBinaryTree(root->right);
        int opt3 =  height(root->left) + height(root->right);

        int ans = max(opt1, max(opt2,opt3));
        return ans;
        
    }
};




class Solution {
private:
    int diameter = 0; // To store the maximum diameter

    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        // Get the height of left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Calculate diameter at this node = leftHeight + rightHeight
        int currentDiameter = leftHeight + rightHeight;

        // Update the maximum diameter found so far
        diameter = max(diameter, currentDiameter);

        // Return height of this node = 1 + max of leftHeight and rightHeight
        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root); // Start recursion to calculate height and diameter
        return diameter; // Diameter is the maximum sum of left + right heights found
    }
};

