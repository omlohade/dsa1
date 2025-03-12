
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

// Example 1:


// Input: p = [1,2,3], q = [1,2,3]
// Output: true
// Example 2:


// Input: p = [1,2], q = [1,null,2]
// Output: false
// Example 3:


// Input: p = [1,2,1], q = [1,1,2]
// Output: false
 

// Constraints:

// The number of nodes in both trees is in the range [0, 100].
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


// DFS Recursive Approach

class Solution {
public:
    // Function to check if two trees are the same
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // CASE 1: Both nodes are NULL → same tree at this point
        if (p == nullptr && q == nullptr)
            return true;

        // CASE 2: One node is NULL and the other isn't → not same
        if (p == nullptr || q == nullptr)
            return false;

        // CASE 3: Both nodes exist but their values are different → not same
        if (p->val != q->val)
            return false;

        // Recursively check:
        // - Left subtrees
        // - Right subtrees
        // Both must be true for trees to be the same
        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return isLeftSame && isRightSame;
    }
};
// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(H), where H is the height of the tree.

// The space complexity is O(H) because the maximum depth of the recursion stack would be H.
// In the worst case, the tree would be skewed and H would be equal to N.

// The time complexity is O(N) because we are visiting each node exactly once.

// The code above is a recursive solution to the problem. We check if the two nodes are the same at the current level and then recursively check if the left and right subtrees are the same.

// If the current nodes are the same and the left and right subtrees are the same, then the trees are the same.

// If any of the conditions fail, we return false.

// The base cases are when both nodes are NULL (same tree) or when one node is NULL and the other isn't (not the same tree).


// Approach 2: Iterative Approach
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front(); q1.pop();
            TreeNode* node2 = q2.front(); q2.pop();

            // Both nodes are NULL, continue
            if (!node1 && !node2)
                continue;       

            // One is NULL, the other isn't → not same
            if (!node1 || !node2)
                return false;

            // Values are different → not same
            if (node1->val != node2->val)
                return false;

            // Push left children of both nodes
            q1.push(node1->left);
            q2.push(node2->left);

            // Push right children of both nodes
            q1.push(node1->right);
            q2.push(node2->right);
        }

        // Both queues should be empty if trees are identical
        return q1.empty() && q2.empty();
    }
};

// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(N), where N is the number of nodes in the tree.

// The space complexity is O(N) because in the worst case, both queues would contain all the nodes of the tree.

// The time complexity is O(N) because we are visiting each node exactly once.

// The code above is an iterative solution to the problem. We use two queues to store the nodes of the two trees.

// We push the root nodes of both trees into their respective queues and then iterate over the queues.

// At each step, we pop the front nodes from both queues and compare them.

// If the nodes are the same, we push their left and right children into the queues.

// If the nodes are different, we return false.

// If we reach the end of the loop and both queues are empty, then the trees are the same.

// If one queue is empty and the other isn't, then the trees are not the same.

// If both queues are not empty, then the trees are not the same.

